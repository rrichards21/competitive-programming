//makes a snake game

//variables
var canvas;
var ctx;
var width;
var height;
var frames = 0;
var score = 0;
var speed = 0.15;
var gameOver = false;
var snake;
var food;

//setup canvas and context
function setup(){
  canvas = document.getElementById("canvas");
  ctx = canvas.getContext("2d");
  width = canvas.width;
  height = canvas.height;
  snake = new Snake();
  food = new Food();
  food.pickLocation();
  window.addEventListener("keydown", function(event){
    snake.changeDirection(event.keyCode);
  });
  window.setInterval(function(){
    if(!gameOver){
      var snakeAteFood = snake.eat(food);
      if(snakeAteFood){
        food.pickLocation();
      }else{
        snake.move();
      }
      var gameOver = snake.checkCollision();
      if(gameOver){
        showGameOver();
      }
    }
  }, speed*1000);
}

//draw the snake and food
function draw(){
  ctx.clearRect(0, 0, width, height);
  snake.draw();
    food.draw();
}


//Snake class
function Snake(){
  this.x = 0;
  this.y = 0;
  this.xspeed = 1;
  this.yspeed = 0;
  this.total = 0;
  this.tail = [];

  //draw the snake
  this.draw = function(){
    ctx.fillStyle = "white";
    for(var i = 0; i < this.tail.length; i++){
      ctx.fillRect(this.tail[i].x, this.tail[i].y, box, box);
    }
    ctx.fillRect(this.x, this.y, box, box);
  }

  //move the snake
  this.move = function(){
    for(var i = 0; i < this.tail.length - 1; i++){
      this.tail[i] = this.tail[i + 1];
    }
    this.tail[this.total - 1] = {x: this.x, y: this.y};

    this.x += this.xspeed * box;
    this.y += this.yspeed * box;

    if(this.x < 0){
      this.x = width - box;
    }
    if(this.y < 0){
      this.y = height - box;
    }
    if(this.x > width - box){
        this.x = 0;
        }
    if(this.y > height - box){
        this.y = 0;
        }
    }

    //change direction of the snake
    this.changeDirection = function(direction){
        switch(direction){
            case 37:
            this.xspeed = -1;
            this.yspeed = 0;
            break;
            case 38:
            this.xspeed = 0;
            this.yspeed = -1;
            break;
            case 39:
            this.xspeed = 1;
            this.yspeed = 0;
            break;
            case 40:
            this.xspeed = 0;
            this.yspeed = 1;
            break;
        }
        }

    //check if the snake has collided with itself
    this.checkCollision = function(){
                for(var i = 0; i < this.tail.length; i++){
            if(this.x === this.tail[i].x && this.y === this.tail[i].y){
                return true;
            }
        }
        return false;
    }

    //check if the snake has eaten the food
    this.eat = function(food){
        if(this.x === food.x && this.y === food.y){
            this.total++;
            return true;
        }
        return false;
    }
}


//Food class
function Food(){
  this.x = 0;
  this.y = 0;

  //pick a random location for the food
  this.pickLocation = function(){
    this.x = Math.floor(Math.random() * ((width - box) / box)) * box;
    this.y = Math.floor(Math.random() * ((height - box) / box)) * box;
  }

  //draw the food
  this.draw = function(){
    ctx.fillStyle = "red";
    ctx.fillRect(this.x, this.y, box, box);
  }
}

//game over message
function showGameOver(){
  ctx.font = "60px Verdana";
  ctx.fillStyle = "white";
  ctx.fillText("Game Over", 10, height/2);
}

//start the game
setup();

//draw the snake and food
var loop = function(){
  draw();
  frames++;
  if(frames % 10 === 0){
      score++;
  }
  document.getElementById("score").innerHTML = score;
  window.requestAnimationFrame(loop);
}

loop();
