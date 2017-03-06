var ctx;

function draw(ctx){
    ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);

    ctx.fillStyle = "#ccc";
    //туловище
    ctx.beginPath();
    ctx.ellipse(ctx.canvas.width/2, ctx.canvas.height/2, 150, 75, 0, 0, 2 * Math.PI);
    ctx.stroke();

    //голова
    ctx.beginPath();
    ctx.arc(366, 214, 42, 0, 2 * Math.PI);
    ctx.stroke();

    //нога левая
    ctx.beginPath();
    ctx.moveTo(439,368.5);
    ctx.lineTo(355,470);
    ctx.stroke();

    //нога правая
    ctx.beginPath();
    ctx.moveTo(480, 374.37);
    ctx.lineTo(514, 490);
    ctx.stroke();

    //крыло
    ctx.beginPath();
    ctx.moveTo(507, 305);
    ctx.lineTo(568, 305);
    ctx.lineTo(602, 404);
    ctx.closePath();
    ctx.stroke();

    //хвост
    ctx.beginPath();
    ctx.moveTo(615, 275);
    ctx.lineTo(726, 275);
    ctx.lineTo(615, 315);
    ctx.closePath();
    ctx.stroke();

    //нос
    ctx.beginPath();
    ctx.moveTo(349, 214);
    ctx.lineTo(349, 188);
    ctx.lineTo(270, 205);
    ctx.closePath();
    ctx.stroke();

}

window.addEventListener('load', function(){
    var infoForm = document.getElementById('info');
    var canvas = document.getElementsByTagName("canvas")[0];
    canvas.width = 1000;
    canvas.height = 600;


    ctx = canvas.getContext("2d");
    draw(ctx);



    canvas.addEventListener('click', function(e){

        for(var i = 0; i < document.forms.length; ++i){
            if (document.forms[i].x && document.forms[i].y) {
                document.forms[i].x.value = e.layerX;
                document.forms[i].y.value = e.layerY;
            }
        }
    });

    canvas.addEventListener('mousemove', function(e){
        //console.log('Drag', e.layerX, e.layerY);
        infoForm.x.value = e.layerX;
        infoForm.y.value = e.layerY;
    });


    document.forms.rotate.addEventListener('submit', function(e){
        console.log('Rotate', e.target.x.value, e.target.x.value, e.target.angle.value);
        ctx.save();
        ctx.translate(e.target.x.value, e.target.y.value );
        ctx.rotate( Math.PI * e.target.angle.value / 180);
        ctx.translate(-e.target.x.value, -e.target.y.value );
        draw(ctx);
        e.preventDefault();
    });

    document.forms.offset.addEventListener('submit', function(e){
        ctx.save();
        ctx.translate(e.target.dx.value, e.target.dy.value );
        draw(ctx);
        e.preventDefault();
    });

    // document.forms.zoom.addEventListener('submit', function(e){
    //     ctx.save();
    //     ctx.lineWidth *= 1/Math.sqrt(e.target.kx.value * e.target.ky.value);
    //     ctx.translate(e.target.x.value, e.target.y.value );
    //     ctx.scale(e.target.kx.value, e.target.ky.value );
    //     ctx.translate(-e.target.x.value, -e.target.y.value );
    //     draw(ctx);
    //     e.preventDefault();
    // });

    // window.addEventListener('keypress', function(e){
    //     if (e.keyCode == 26 && e.ctrlKey == true)
    //         ctx.restore();
    //
    //     switch (e.keyCode){
    //         case 119:
    //             ctx.save();
    //             ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
    //             ctx.translate(0, -50);
    //             break;
    //         case 97:
    //             ctx.save();
    //             ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
    //             ctx.translate(-50, 0);
    //             break;
    //         case 115:
    //             ctx.save();
    //             ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
    //             ctx.translate(0, 50);
    //             break;
    //        case 100:
    //             ctx.save();
    //             ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
    //             ctx.translate(50, 0);
    //             break;
    //     }
    //
    //     draw(ctx);
    // });

});