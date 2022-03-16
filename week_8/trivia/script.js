document.addEventListener('DOMContentLoaded', function() {





let btnCorrect = document.querySelector('#correct');
btnCorrect.addEventListener('click', function(){
    btnCorrect.style.backgroundColor = 'green';
    document.querySelector('#feedback0').innerHTML = 'Correct!'
});




let btnIncorrect0 = document.querySelector('#incorrect0');
btnIncorrect0.addEventListener('click', function(){
    btnIncorrect0.style.backgroundColor = 'red';
    document.querySelector('#feedback0').innerHTML = 'Incorrect!'
});

let btnIncorrect1 = document.querySelector('#incorrect1');
btnIncorrect1.addEventListener('click', function(){
    btnIncorrect1.style.backgroundColor = 'red';
    document.querySelector('#feedback0').innerHTML = 'Incorrect!';
});


document.getElementById("check").onclick = function(){
    var amser = document.getElementById("answer").value;
    if (amser != "Stalin")
        {
            document.querySelector('#feedback1').innerHTML = 'Incorrect!'
        }
    else
        {
            document.querySelector('#feedback1').innerHTML = 'Correct!'
        }
}

});