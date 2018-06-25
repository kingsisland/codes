var slideinterval = 500;

var i=0;
function getFigures()
{
    return document.getElementById('carousel').getElementsByTagName('figure');
}
function moveForward () {
   var figures= getFigures();
   var figLength=figures.length;
   
       if( figures[i%figLength].className=='visible'){
        figures[i%figLength].className='';
        ++i;
        figures[i%figLength].className='visible';
       }
       //setTimeout(moveForward,slideinterval);
   
}
//moveForward();
function startPlayback () {
    moveForward();
    setTimeout(startPlayback,slideinterval);
    
}

startPlayback();