#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    //TODO
    //Open the memory card
    BYTE buffer[512];
    FILE *f = fopen(argv[1], "r");

    if (!f)
    {
        return 1;
    }
    char filename[8];
    int counter = 0;
    FILE *img = NULL;
    while (fread(buffer, sizeof(BYTE), 512, f) == 512)
    {
        //TODO
        //Look for the beginning of a jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If it's the first file, go ahead and start writing as usual
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, img);
                counter++;
            }
            //If a new file is found, create the next one and start writing 
            else if (counter > 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, img);
                counter++;
            }
        }
        //If the next block isn't a file, just keep writing in the current file (same as 00counter)
        else if (counter > 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }

    fclose(f);
    fclose(img);
}
//TODO
//Once you find the file, keep writing data in 512 byte chunks until you find a new JPEG file
//at which point you can close the old one and start writing the new one
