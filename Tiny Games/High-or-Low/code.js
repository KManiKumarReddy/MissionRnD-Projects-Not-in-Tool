var score;

$("#displaynum").on("swipeleft",function(){
	var presentNum = parseInt(document.getElementById("displaynum").innerHTML);
	var previousNum = parseInt(document.getElementById("prevnum").innerHTML);
	var randomNum = 0;
	while((randomNum= Math.floor(Math.random() * 100))== presentNum);
	if(presentNum < previousNum) {
		score = score + 1;
		document.getElementById("result").innerHTML = "SCORE: " + score;
		$("body").attr("bgcolor", "#C1FFC1");
	}
	else {
		document.getElementById("result").innerHTML = "SCORE: " + score;
		$("body").attr("bgcolor", "#FFC1C1");
		window.navigator.vibrate(200);
		//document.getElementById("ping").play();
	}
	document.getElementById("prevnum").innerHTML = presentNum;
	document.getElementById("displaynum").innerHTML = randomNum;
	$("p").hide();
});

$("#displaynum").on("swiperight",function(){
	var presentNum = parseInt(document.getElementById("displaynum").innerHTML);
	var previousNum = parseInt(document.getElementById("prevnum").innerHTML);
	var randomNum = Math.floor((Math.random() * 100));
	if(presentNum > previousNum) {
		score = score + 1;
		document.getElementById("result").innerHTML = "SCORE: " + score;
		$("body").attr("bgcolor", "#C1FFC1");
	}
	else {
		document.getElementById("result").innerHTML = "SCORE: " + score;
		$("body").attr("bgcolor", "#FFC1C1");
		window.navigator.vibrate(200);
		//document.querySelector("#ping").play();
	}
	document.getElementById("prevnum").innerHTML = presentNum;
	document.getElementById("displaynum").innerHTML = randomNum;
	$("p").hide();
});

$(document).ready(function() {
	document.getElementById("displaynum").innerHTML = Math.floor(Math.random() * 100);
	score = -1;
	$("body").attr("bgcolor", "#FFFFC1");
	$("#timeup").hide();
	$("#reload").hide();
	function showTimeUP() {
		$("#displaynum").hide();
		$("#timeup").show();
		$("body").attr("bgcolor", "#FFFFC1");
		$("p").hide();
		$("#reload").show(200);
	}
	window.setTimeout(showTimeUP, 20000);
});