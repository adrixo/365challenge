http://jsfiddle.net/URMN6/1/

var circles = [
    [0.479477, -0.634017,  0.137317],
    [-0.568894, -0.450312, 0.211238],
    [-0.907263, -0.434144,  0.668432],
    [0.279875,  0.309700,  0.242502],
    [-0.999968, -0.910107, 0.455271],
    [0.889064, -0.864342, 1.292949],
    [-0.701553,  0.285499, 0.321359],
    [-0.947186,  0.261604, 0.028034],
    [0.805749, -0.175108,  0.688808],
    [0.813269, -0.117034, 0.340474],
    [-0.630897, -0.659249, 0.298656],
    [-0.054129, -0.661273, 0.270216],
    [0.042748,  0.469534, 0.759090],
    [0.079393, -0.803786,  0.635903],
    [-0.987166,  0.561186,  0.740386],
    [-0.246960, -0.774309,  1.035616],
    [-0.189155, -0.244443, 0.187699],
    [0.683683, -0.569687,  0.275045],
    [-0.249028, -0.452500,  0.713051],
    [-0.070789, -0.898363,  0.135069]
];

var cvs = document.getElementById("cvs");
var ctx = cvs.getContext("2d");
var w = cvs.width;
var h = cvs.height;

// fill background with white
ctx.beginPath();
ctx.rect(0, 0, w, h);
ctx.closePath();
ctx.fillStyle = "#fff";
ctx.fill();

// draw circles in black
ctx.fillStyle = "#000";
// translate and scale circles to better fit on canvas
var scale = w*0.25;
var transX = w*0.44;
var transY = w*0.55;
for (var i = 0; i < circles.length; i++) {
    var circle = circles[i];
    var x = circle[0] * scale + transX;
    var y = circle[1] * scale + transY;
    var r = circle[2] * scale;
    ctx.beginPath();
    ctx.arc(x, y, r, 0, Math.PI*2, true);
    ctx.closePath();
    ctx.fill();
}

// count number of black pixels
var data = ctx.getImageData(0, 0, w, h).data;
var hits = 0;
var total = w*h;
for (var i = 0; i < total; i++) {
    if (data[i*4] < 128) {
        ++hits;
    }
}

// calculate area of canvas in circle coordinate system
var topleft = [0 - transX, 0 - transY];
var botright = [w / scale - transX, h / scale - transY];
var a = (botright[0]-topleft[0])*(botright[1]-topleft[1]);

// display result
alert((hits/total)*a);
