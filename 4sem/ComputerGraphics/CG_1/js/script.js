var ctx;
var points = [];
var totalPointCount = 0;

function Point(x, y) {
    this.x = x;
    this.y = y;
}

function draw(ctx){
    ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);

    ctx.fillStyle = "#ccc";

    ctx.beginPath();
    ctx.moveTo(507, 305);
    ctx.lineTo(568, 305);
    ctx.lineTo(602, 404);
    ctx.closePath();
    ctx.stroke();

}

window.addEventListener('load', function(){
    var infoForm = document.getElementById('info');
    var canvas = document.getElementsByTagName("canvas")[0];
    canvas.width = 600;
    canvas.height = 500;

    ctx = canvas.getContext("2d");
    draw(ctx);

    canvas.addEventListener('click', function(e){

        for(var i = 0; i < document.forms.length; ++i){
            document.getElementById('idParent').innerHTML += '<div id="idChild"> content html </div>';
        }
    });

    canvas.addEventListener('mousemove', function(e){
        //console.log('Drag', e.layerX, e.layerY);
        infoForm.x.value = e.layerX;
        infoForm.y.value = e.layerY;
    });


    window.addEventListener('keypress', function(e){

        //ctx.restore();

        switch (e.keyCode){

        }
    });

});