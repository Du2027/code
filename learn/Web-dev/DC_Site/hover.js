const field = document.getElementById("over-side");
const next_to = document.getElementById("next-to-side");
const beginn= -80;
field.addEventListener("mouseover",(event) =>{field.style.left=0});
field.addEventListener("mouseout",(event) =>{console.log("out")});