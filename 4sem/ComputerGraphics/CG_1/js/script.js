var ctx;
var points = [];
var totalPointCount = 0;
var scale = 1;
var pointRadius = 5;

function Point(x, y) {
    this.x = x;
    this.y = y;
}

function draw(ctx){
    ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);

    ctx.fillStyle = "#ccc";

    ctx.beginPath();
    ctx.moveTo(ctx.canvas.width / 2, 0);
    ctx.lineTo(ctx.canvas.width / 2, ctx.canvas.height);
    //ctx.closePath();

    //ctx.beginPath();
    ctx.moveTo(0, ctx.canvas.height / 2);
    ctx.lineTo(ctx.canvas.width, ctx.canvas.height / 2);


    for (let i = 0; i < points.length; i++) {
        ctx.arc(points[i].x, points[i].y, pointRadius, 0, Math.PI * 2, true);
    }

    ctx.closePath();
    ctx.stroke();

}

function updatePointsList() {
    var text = '<fieldset id="dotsview"> <legend>Точки</legend>';
    for (let i = 0; i < points.length; i++) {
        text += '<row id="{0}"> <column cols="4"> <input type="text" name="x" value="{1}" disabled/> </column> <column cols="4"> <input type="text" name="y" value="{2}" disabled/> </column> <column cols="4"> <button small type="primary" onclick="deletePoint({0});">Удалить</button> </column> </row>'.format(i, points[i].x, points[i].y);
    }
    text += '</fieldset>'
    document.getElementById('dots').innerHTML = text;
    draw(ctx);
}

function addPoint(x, y) {
    points.push(new Point(x,y));
    updatePointsList();
}

function deletePoint(index) {
    points.splice(index, 1);
    updatePointsList();
}

window.addEventListener('load', function(){
    if (!String.prototype.format) {
        String.prototype.format = function() {
            var args = arguments;
            return this.replace(/{(\d+)}/g, function(match, number) {
                return typeof args[number] != 'undefined'
                    ? args[number]
                    : match
                    ;
            });
        };
    }

    var infoForm = document.getElementById('info');
    var canvas = document.getElementsByTagName("canvas")[0];
    canvas.width = 600;
    canvas.height = 500;

    ctx = canvas.getContext("2d");
    draw(ctx);

    canvas.addEventListener('click', function(e){
            addPoint(e.layerX, e.layerY);
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