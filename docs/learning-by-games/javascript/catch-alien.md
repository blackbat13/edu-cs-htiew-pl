# Złap kosmitę

## Pełna gra

```javascript
import kaboom from "kaboom";

kaboom();

loadSprite("alien", "sprites/alien.png");

let score = 0;

const scoreText = add([
  text(score),
  pos(width() / 2, 40),
  origin("center"),
]);

const alien = add([
  sprite("alien"),
  pos(center()),
  origin("center"),
  area(),
]);

alien.vx = 90;
alien.vy = 100;
alien.clicks(onClickAlien);

action(update);

function update() {
  alien.move(alien.vx, alien.vy);

  if (alien.pos.x > width() - alien.width / 2 || alien.pos.x < alien.width / 2) {
    alien.vx *= -1
  }

  if (alien.pos.y > height() - alien.height / 2 || alien.pos.y < 0) {
    alien.vy *= -1;
  }

  alien.vx += rand(-5, 5);
  alien.vy += rand(-5, 5);
  
  scoreText.text = score;
}

function onClickAlien() {
  score++;
  alien.pos.x = rand(alien.width / 2, width() - alien.width / 2);
  alien.pos.y = rand(0, height() - alien.height / 2);
  alien.vx = rand(80, 650);
  alien.vy = rand(80, 650);

  if (rand() < 0.5) {
    alien.vx *= -1;
  }

  if (rand() < 0.5) {
    alien.vy *= -1;
  }
}
```



{% embed url="https://replit.com/@damiankurpiewski/CatchAlien-1#code/main.js" %}
