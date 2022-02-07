# HELLO and WELCOME

As a team we thought of combining some classic games that occupy a large part of our memories in **"well designed"** gaming platform ,  gathering all the information that we've learned during this semester. we tried to produce a result that meets the absolute dedication of our dear teacher .

## table of contents 

- Introduction 
- home interface
- 2048 game
   - overview
   - the idea!
   - the algorithm
     - win/lose conditions 
     - movements

 - Minesweeper
   - overview
   - cell
   - setup container
   - right/left clickes actions
   - empty cell
   - big bang
   - Win check
   - Timer
   - sound effects
- test



## Introduction:

*We've developed 2 games in this project so we thought of creating a home page in which we can choose what game we want to play , its main job is to redirect us  back in forth between the games.*
* *we tried to make a clean, simple home interface with animated pushButtons.*  (as you can see in the GIF below)

![My Video1 (1)](https://user-images.githubusercontent.com/79703342/152829337-dd7359be-9ea8-4bda-9011-e58dc533adc3.gif)

these small animations was done through [QProprety Animation](https://doc.qt.io/qt-5/qpropertyanimation.html#details) class that animates Qt properties
and here is the impletation code 

``` c++
    animation2 = new QPropertyAnimation(ui->pushButton_2,"geometry");
    animation2->setDuration(600);
     animation2->setStartValue(ui->pushButton->geometry());
     animation2->setEndValue(QRect(200,350,200,100));
     animation2->start();

     animation = new QPropertyAnimation(ui->pushButton,"geometry");
     animation->setDuration(600);
      animation->setStartValue(ui->pushButton->geometry());
      animation->setEndValue(QRect(600,350,200,100));
      animation->start();
      
```

* *once you click on a certain game (2048 for example) a dialog appears showing a set of rules and a button box that directs you to the game.*
  * ***2048***
![image](https://user-images.githubusercontent.com/79703342/152773854-9c6aa40c-6430-460f-9a8a-8fe5822f823f.png)  

   * ***minesweeper***
![image](https://user-images.githubusercontent.com/79703342/152774217-c26bb8c6-10dd-470c-a9b3-badb82b0c707.png)  

  
 ***Now let's dive into our games development!***    
  



# 2048  


## OVERVIEW

***2048*** is played on a 4 × 4 square grid, with tiles of various colors and values ​​(but always [powers of two](https://fr.wikipedia.org/wiki/Puissance_de_deux "power of two") ) that can be moved with a [scrolling](https://fr.wikipedia.org/wiki/D%C3%A9filement_parallaxe "Parallax scrolling") animation when the player presses the [arrow keys](https://fr.wikipedia.org/wiki/Touches_fl%C3%A9ch%C3%A9es "Arrow keys") on their keyboard [1](https://fr.wikipedia.org/wiki/2048_(jeu_vid%C3%A9o)#cite_note-spence-1) (or with the touch function on [tablets](https://fr.wikipedia.org/wiki/Tablette_informatique "tablet computer") and [smartphones](https://fr.wikipedia.org/wiki/Smartphones "smartphones") ). For the highest values, the tiles glow slightly after merging the previous two tiles and change color.

![image](https://user-images.githubusercontent.com/79703342/152719678-792f2cef-bb9e-4ba7-b525-aec0209bb5f8.png)



**We used the designer tool to create:**
* A gridLayout that will contain 16 cell (4x4).
* Score counter.
* A pushButton that will redirect us to the main interface.
* And of course the Logo.

![image](https://user-images.githubusercontent.com/79703342/152720122-daf97f18-aaa7-4358-9a64-5c879870dd2c.png)

## THE IDEA!

Since there would be no animations, the cells should be static, 2 main approaches came to my mind:
* *We create a class in which we link the number with  the color of each case (2,4,8,16...), and then display them in **16 widgets** depending on which number exists in which cell *(too long I couldn't even explain it properly*).*
* *We create a normal grid in which we do the math and we display the content of it in the form of pictures, so whenever the content of the grid change, we change the border image of the appropriate item in our* *layout (UI)*.    ***the one we used!***
	
	 * now what type of item should we use, [QGraphicsView](https://doc.qt.io/qt-5/qgraphicsview.html) seemed ideal for our case , it's true we didn't use it to its full potential since it's so powerful.  
	 
	```cpp
		void game2::SHOW()
	{
	    for (auto i=0;i<4;i++) {
	        for (auto j=0;j<4;j++) {
	            int coordinates=i*4+j;
	            QGraphicsView *gv=nullptr;
	            switch (coordinates) {
	            //gv1~gv16 are graphicsviews created in the UI
	            case 0: gv=ui->gv1;break;case 1: gv=ui->gv2;break;	            
	            case 2: gv=ui->gv3;break;case 3: gv=ui->gv4;break;
	            case 4: gv=ui->gv5;break;case 5: gv=ui->gv6;break;
	            case 6: gv=ui->gv7;break;case 7: gv=ui->gv8;break;
	            case 9: gv=ui->gv10;break;case 8: gv=ui->gv9;break;
	            case 10: gv=ui->gv11;break;case 11: gv=ui->gv12;break;
	            case 12: gv=ui->gv13;break;case 13: gv=ui->gv14;break;
	            case 14: gv=ui->gv15;break;case 15: gv=ui->gv16;break;
	            default:break;
	            }
	            /* gridboard is the main board in which we do all 
	            the math */
	            switch(game.gridboard[i][j])
	            {
	            //we 've added these images to the ressouces file
	            case 0:gv->setStyleSheet("border-image:url(:/0.png)");break;
	            case 2:gv->setStyleSheet("border-image:url(:/2.png)");break;
	            case 4:gv->setStyleSheet("border-image:url(:/4.png)");break;
	            case 8:gv->setStyleSheet("border-image:url(:/8.png)");break;
	            case 16:gv->setStyleSheet("border-image:url(:/16.png)");break;
	            case 32:gv->setStyleSheet("border-image:url(:/32.png)");break;
	            case 64:gv->setStyleSheet("border-image:url(:/64.png)");break;
	            case 128:gv->setStyleSheet("border-image:url(:/128.png)");break;
	            case 256:gv->setStyleSheet("border-image:url(:/256.png)");break;
	            case 512:gv->setStyleSheet("border-image:url(:/512.png)");break;
	            case 1024:gv->setStyleSheet("border-image:url(:/1024.png)");break;
	            case 2048:gv->setStyleSheet("border-image:url(:/2048.png)");break;
	            default:break;
	            }
	        }
	    }
	    ui->label_2->setText(QString::number(game.score));
	}
	```
				
	 ***N. This is the main displaying function, whenever a move is made we call this function***



## THE ALGORITHM!

***NOTE: We 've managed to create this after reading some articles about the game and discussing it with some of our colleagues, so you sir might spot some similarities.***
1. **Let's start by the WIN and LOSE conditions:**
### It's not that hard, why do I keep losing?!
*  *you win this game when the number 2048 appears in your grid pretty simple right? Let's code it then:*
	```cpp
	bool Game::WIN()
		{
	 for (auto i = 0; i <4; i++)
		    {
		for (int j = 0; j <4; ++j)
		{
		    if (gridboard[i][j]==2048)return true;
			else return false;
		}}}
	```
*  *you lose when 2 conditions are met, the first is that there is no cell containing 0, the second is there should be no duplicates beside each other in the whole grid.*
	```cpp
			bool Game::LOSE(){
		    for (auto i = 0; i < 4; i++)
		    {
		        for (auto j = 0; j <4; j++)
		        {
		            if (gridboard[i][j] == 0)
		            {
		                return false; //if this condition is met there 
		                              //is no need to check the other
		            }
		        }
		    }
		    for (auto i = 0; i < 4 - 1; i++)
		    {
		        for (auto j = 0; j < 4 - 1; j++)
		        {
		        if (gridboard[i][j]== gridboard[i][j+1])
		            {
		                return false
		            }
		   else if (gridboard[j][i]== gridboard[j+1][i])
		            {
		                return false
		            }
		        }
		    }
		    return true;}
	```
2. **Now the movements:**
### *Maaan*, I didn't mean to move that one!
*There are four basic movements **up** , **down** , **left** , **right** , each one of them will move the whole grid, adding up the duplicates and translating the other cells.*  
			
	The same algorithm goes for all of them so we will be covering just one:
*it's pretty simple to understand, 0s get crushed, duplicates gets added.*
* *There are 4 main steps in our approach:*  

  * ***Step1** shifting: whenever you find a 0 beside a 2^n you replace them according to the direction (up in our case) and you repeat this process until until you find a number.*  
  
    * ***ex: the extreme case 0002->2000*** we should shift the 2 three times in order to do a full shift .
    ```cpp
     for (auto i = 0; i <4; i++)
	    { for (auto count= 0; count <3; count++){
            for (auto j = 0; j <4 - 1; j++)
            {
                if (gridboard[j][i] == 0)
                {
						    if(gridboard[j+1][i] != 0)
						    {condition = true;}//in step4
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j + 1][i];
                    gridboard[j + 1][i] = temp;
           }}}
    ```
   * ***Step2** adding up duplicates: this one is simple if you find a similar number add the two.*  
    ```cpp
	   for (auto i = 0; i < 4 - 1; i++) {
	    for (auto j = 0; j < 4 - 1; j++)
	        {
	            if (gridboard[j][i] == gridboard[j + 1][i])
            {   if(gridboard[j][i] != 0){condition = true;}//in step4
	              gridboard[j][i] = gridboard[j][i] * 2;
	              score = gridboard[j][i] + score;
	              gridboard[j + 1][i] = 0;
	             }
	         }}
    ```

   * ***Step3** repeat Step1: you need to reshift after adding.*
     * ***ex. 0220** if we don't reshift we will have **0400** (the result we want is **4000**)*  
	```cpp
	 for (auto i = 0; i < 4 - 1; i++){
	   for (auto count= 0; count <3; count++){
	       for (auto j = 0; j < 4 - 1; j++)
	        {
	           if (gridboard[j][i] == 0)  
	       {
	            auto temp = gridboard[j][i];
	            gridboard[j][i] = gridboard[j + 1][i];
	            gridboard[j + 1][i] = temp;
	       }
	  }}}
	```
	* ***Step4** adding a random number {2,4} in a random place every time we shift(**condition1**) or add 2 cells that are different than 0 (**condition2**):*
	  * *I've commented in step 4 **"in step4"** after some lines in the codes above those are the conditions.*
	  * *Now after checking if the game is ongoing and if the our bool variable is true we call our function `AddRandom()`, which choose 2(80%) or 4(20%) and put it in a random free position(contains 0) in the grid.*  
	  
	```cpp
	if(!WIN() && !LOSE())
	 {
	     if(condition){
	        AddRandom();
	        condition = false;
	}}
	```
	```cpp
	void Game::AddRandom()
	{
	    vector<int> choice = { 4, 2, 2, 2, 2, 4, 2, 2, 2, 2};
	    int temp = rand() % choice.size()  ;
	    int x = rand() % 4;
	    int y = rand() % 4;
	    while (gridboard[x][y] != 0)
	    {
	        x = rand() % 4;
	        y = rand() % 4;
	    }
	    gridboard[x][y] = choice[temp];
	    condition = false;
	}
	```
3. ***KeyPressEvent and win/lose action  :***
  * as you can see we recast the function `SHOW()` whenever we make a move.
	```cpp
	void game2::keyPressEvent(QKeyEvent *event)
	{
	    if(event->key()==Qt::Key_Escape)
	    {
	        this->close();
	    }
	    if(event->key()==Qt::Key_R)
	    {

	        game.Restart();

	    }
	    if(event->key()==Qt::Key_Up)
	    {
	        game.Up();

	    }
	    if(event->key()==Qt::Key_Left)
	    {
	        game.Left();
	    }
	    if(event->key()==Qt::Key_Right)
	    {
	        game.Right();
	    }
	    if(event->key()==Qt::Key_Down)
	    {
	        game.Down();
	    }
	    if(game.LOSE())
	    {
	        lab->setText("You lost, wanna continue");
	        dialog->show();
	     }
	    if(game.WIN())
	    {
	        lab->setText("you win, wanna continue？");
	        dialog->show();
	    }
	    this->SHOW();
	}
	```
	* ***as you clearly can see sir everything is working just fine.***
	  
      </br>

	![My Video5](https://user-images.githubusercontent.com/79703342/152832166-fb67183c-3c34-4e97-8b3d-7350407f136c.gif)
  **DONE !**  

# 2.Minesweeper

## OVERVIEW


**Minesweeper** ,which is a single-player puzzle video game. The objective of the game is to clear a rectangular board containing hidden "mines" or bombs without detonating any of them, with help from clues about the number of neighboring mines in each field.

![My Video3](https://user-images.githubusercontent.com/79703342/152830884-1ff32d6c-545a-4a73-8a16-9985737ea744.gif)

We are going to use qt designer to create our interface composed of two buttons , lcd number and a QGridLayout container.

![image](https://user-images.githubusercontent.com/79703342/152831111-f38b80f6-7fbb-48a2-978d-5d7785593e97.png)


# Cell

Fisrt thing we need  is to create a cell class with whom we are going to fill our container

- we need to set the status of each cell if its a flag , bomb ... based on the user actions
- 1 the constructor must include this code
```cpp
   cell::cell(bool bomb, QWidget * parent) : QPushButton(parent)
   {
    bombCount=0;
    flagged=false;
    boxState=BoxState::unclicked;
    setBomb(bomb);
    update();
   }
```
> the constructor takes a boolean attribute named bomb wich is genarated randomly in the mainwindow class
- now we need a bomb setter and a function that returns that a cell is clicked
```cpp
    void cell::setBomb(bool b){
         bomb=b;
    }
    bool cell::isClicked(){
    return (boxState==BoxState::clicked);
    }
```
- if a cell is clicked we need to know if its a bomb or not and update 
```cpp
   bool cell::boxClicked(){


    if(bomb){
        boxState=BoxState::exploded;
    }else{
        boxState=BoxState::clicked;
    }
    update();
    return bomb;
   }

```
-  if a cell is right clicked it turns into a flag
```cpp
   bool cell::boxRightClicked(){
   
    setStyleSheet("QPushButton {image: url(:/flag.png);}");
    flagged=true;
    return bomb;
   }
```
-  we create a function that displays on the button the number of bombs that are around it. 
```cpp
void cell::setBombCount(int c){
    if(c!=0)setText(QString::number(c));
}
```
- we've also created a mouse press event that emits a mouse right click signal and prevent emiting a signal when the box is flagged.
```cpp
   void cell::mousePressEvent(QMouseEvent *e)
   {
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton && !flagged)
        emit clicked();
   }
```
-  now the update function , it changes the style of a cell based on the state of it.
```cpp
  void cell::update(){
    QString style="";
    if(boxState==BoxState::unclicked){

       style+="QPushButton { image: url(:/box.png);border-style: inset;border:0px;}";
        setText("");
    }else if(boxState==BoxState::clicked){
        style+="QPushButton {background-color: rgb(220,220,220);border-style: inset;}";
        setEnabled(false);
    }else if(boxState==BoxState::exploded){
         style+="QPushButton {image: url(:/bomb.png);border-style: inset;}";
        setEnabled(false);
    }
    setStyleSheet(style);

}
```
-  to know the state of each cell we created an  enum class called BoxState that contains the different unchangeable states of the box
```cpp
enum class  BoxState
{
    unclicked, clicked, exploded
};
```

# setup container

now lets setup our container 
- we use QSignalMapper to create a left and right signal that are going to  connect left and right clicked actions to the cells
- we used a randbool fucntion to change randomly the state of a cell to a bomb  
```cpp
  bool MainWindow::randbool(int w){
    return (rand()%w)==0;
  }
```
- we added some style to our cells
```cpp
void MainWindow::setupContainer(){

    QSignalMapper *Left;
    QSignalMapper *Right;
    Left = new QSignalMapper(this);
   Right = new QSignalMapper(this);
    connect(Left, SIGNAL(mapped(int)),this, SLOT(boxL(int)));
    connect(Right, SIGNAL(mapped(int)),this, SLOT(boxR(int)));
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
          bool bomb=randbool(5);
            grid[i][j] = new cell(bomb);
            auto bobo = grid[i][j];
            
             bobo->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding );
              bobo->setFocusPolicy(Qt::NoFocus);
              bobo->setMinimumSize(40,40);
              bobo->setContentsMargins(0,0,0,0);
              bobo->setMaximumSize(40,40);
            QFont f =bobo->font();
            f.setPointSize(19);
            bobo->setFont(f);
            ui->container->addWidget(bobo,i,j);
            Left->setMapping(bobo,(i*1000)+j);
            Right->setMapping(bobo,(i*1000)+j);
            connect(bobo,SIGNAL(clicked()),Left,SLOT(map()));
            connect(bobo,SIGNAL(rightClicked()),Right,SLOT(map()));

        }
    }
}
```

# leftclicked action

- if a box is left clicked , we check if its  a bomb so we execute the bigbang function that explodes all the bombs or we need to set a bomb count of how many are around the box, and of course we check if we won
``` cpp
void MainWindow::boxL(int i){
    click.play();
    if(t==0)
        timer->start(1000);
    if(!isGameOngoing)return;
    int p[2];
    p[0]=i/1000;
    p[1]=i%1000;

    cell* bobo=grid[p[0]][p[1]];
    if(bobo->bomb){
        bigbang();
        bobo->boxClicked();
        return;
    }
    bobo->boxClicked();
    clear(p[0],p[1]);
    winCheck();

}
```
# rightclicked action
- for the right clicked Slot we set the cell status to flagged 
```cpp
void MainWindow::boxR(int id){
    click.play();
    if(t==0)
        timer->start(1000);
    if(!isGameOngoing)return;
    int p[2];
    p[0]=id/1000;
    p[1]=id%1000;

    cell* b=grid[p[0]][p[1]];
    b->boxRightClicked();
    winCheck();
}
```
# clear the empty cells
- to clear the empty cells we used a recursive way that checks the states of each cell around our current cell and examine if they are empty or not
  
```cpp
void MainWindow::clear(int x,int y){
    grid[x][y]->boxClicked();
    grid[x][y]->setBombCount(findBombCount(x,y));
    if(findBombCount(x,y)==0){
        for(int i=-1;i<=1;i++){
            if(x+i<0 || x+i>10-1)continue;
            for(int j=-1;j<=1;j++){
                if(y+j<0 || y+j>10-1 || (i==0 && j==0))continue;
                if(!grid[x+i][y+j]->isClicked()){
                    clear(x+i,y+j);
                }
            }
        }

    }else{
        return;
    }
}
```
- now let's  finds out how many bombs are around a specific cell
``` cpp
int MainWindow::findBombCount(int x,int y){
    int count=0;
    for(int i=-1;i<=1;i++){
        if(x+i<0 || x+i>9)
            continue;
        for(int j=-1;j<=1;j++){
            if(y+j<0 || y+j>9 || (i==0 && j==0))
                continue;

            cell* cell=grid[x+i][y+j];
            if(cell->bomb)count++;
        }
    }
    return count;
}
```
# bigbang
- this function is going to explode all the bombs in our map and its executed when a box that contains a bomb is clicked

  ![Capture d’écran 2022-02-07 001524](https://user-images.githubusercontent.com/85891554/152705674-b46924ce-5b67-4242-8b0d-366692b403ac.png)


```cpp
void MainWindow::bigbang(){

    lost.play();
    ui->pp->setStyleSheet("QPushButton { image: url(:/dead.png);background: transparent;}");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cell *bobo=grid[i][j];
            if(bobo->bomb){
                bobo->boxClicked();
            }

        }
    }
    timer->stop();

    isGameOngoing=false;
}
```  

> **NOTICE** that the value of  isGameOngoing=false which means that the current game will end  until we start a new game using the dead face button
# win check
- to check if we won or not we need to be sure that all the  boxes that do not include bombs are  clicked and that the cells that are flagged are bombs
```cpp
bool MainWindow::winCheck(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cell *bobo=grid[i][j];

            if(!bobo->bomb && !bobo->isClicked())return false;
            if(!bobo->bomb && bobo->flagged)return false;
        }
    }
 lost.setMedia(QUrl("qrc:/w.mp3"));
 lost.play();
    isGameOngoing=false;
    return true;
}
```
# timer
 in this game the score is the time it took us to complete the game  

  - we need to connect a timer to a slot that shows the time on our lcd number
```cpp
  connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
```
  - showtime slot
```
```cpp
  void MainWindow::showTime()
  {
    t++;
    ui->lcdNumber_2->display(t);
  }
```
  - this timer start after the first action so we need to add this code to the first left or right clicked action
```cpp
  if(t==0)
        timer->start(1000);
```
  - and it stops if we click on a bomb ,that's why  we've addes this line of code to the end of the bigbang function
  
```cpp
  timer->stop();
```

# sound effects

- we added a song to the game using [QMediaPlayer](https://doc.qt.io/qt-5/qmediaplayer.html#details)
which is is a high level media playback class. It can be used to playback such content as songs, movies and internet radio.

QMediaPlayer sing;

- now in our constructor we need to add this code so the sound start

```cpp
sing.setMedia(QUrl("qrc:/classic.mp3"));
sing.play();
```
- to stop the song we have to click on the mute button wich is connected to the cms slot
```cpp
void MainWindow::cms(){
    a= !a;
    if(a){
        sing.play();
        ui->pp1->setStyleSheet("QPushButton { image: url(:/sound.png);background: transparent;}");
    }else{
        sing.stop();
        ui->pp1->setStyleSheet("QPushButton { image: url(:/mute.png);background: transparent;}");
    }

}
```
- we are going to do the same thing for the win , lost  and click sounds
  

# new game
- to start a new game we need to click on the smily face in the middle of our game
- this button is connected to the new slot and it turns to a dead face if we lose the game  
  
```cpp
void MainWindow::newg(){
     lost.setMedia(QUrl("qrc:/lost.mp3"));
    timer->stop();
    r=0;
    t=0;
    ui->pp->setStyleSheet("QPushButton { image: url(:/smile.png);background: transparent;}");

    setupContainer();
    isGameOngoing=true;
}
```

# test

***Don't miss*** this video , it's a test to the whole platform  

https://user-images.githubusercontent.com/79703342/152834798-6074c18b-80dc-43b0-a87c-6d3126c69a6f.mp4


# to sum up 

we've learned a lot not only from this project but from all the previous  sessions , hope we will be up to your expectations.

**Big thanks**


     
