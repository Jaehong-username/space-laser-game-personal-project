#include "Player.h"

void Player::updateMove(sf::RenderWindow& target)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x >= 0){
        cout << "Left" << endl;
        position.x -= movement.x;
        //movement.x = - 20.f;
        //this->move(position);
        
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x <= target.getSize().x - 100){
        cout << "Right" << endl;
        position.x += movement.x;
        //movement.x = 20.f;
        //this->move(position);
       
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && position.y >= 0){
        cout << "Up" << endl;
        position.y -= movement.y;
        //movement.y = - 20.f;
        //this->move(position);
        
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y <= target.getSize().y - 100){
        cout << "Down" << endl;
        position.y += movement.y;
        //movement.y = 20.f;
        //this->move(position);
        
    }

    //MAKE SURE TOput image as an object to move the player!!!!! not the player itself!!
    image.setPosition(position);
}

void Player::updateLaser(sf::RenderWindow& target)
{
    for (int i = 0; i < laserVec.size(); i++)
    {
        laserVec[i]->updateMove(target);
        if (laserVec[i]->checkLaserOut()){ //check if the laser is out of the scrren
            delete laserVec[i];
            laserVec.erase(laserVec.begin() + i); //remove that laser out of the vector
            cout << "Laser out of the screen!" << endl;

            //laserVec.shrink_to_fit();
        }
    }
}

void Player::shootLaser()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        cout << "L" << endl;
        laser = new Laser (this->position); //allocate space on the heap
        laserVec.push_back(laser);
    }
}

void Player::drawLaser(sf::RenderTarget& target)
{
    for (int i = 0; i < laserVec.size(); i++)
    {
        target.draw(laserVec[i]->getImage());
    }
}

void Player::loseHealthBar()
{
    //delete healthBar.end() - 1;
    healthBar.pop_back();
}

void Player::drawHealthBar(sf::RenderTarget& target)
{
    for (int i = 0; i < healthBar.size(); i++)
    {
        target.draw(*healthBar[i]);
    }
}

vector<Laser*>& Player::getLaserVec()
{
    return this->laserVec;
}

int Player::getHealth()
{
    return this->health;
}

int Player::getInvincibleBufferTime()
{
    return this->invincibleBufferTime;
}

void Player::setHealth(int health)
{
    this->health = health;
}

void Player::setInvincibleBufferTime(int time)
{
    this->invincibleBufferTime = time;
}

void Player::createHealthBar()
{
    
    float updatedxPos = 100.f;
    for (int i = 0; i < 10; i++)
    {
        healthShape = new CircleShape;
        healthShape->setFillColor(Color::Red);
        healthShape->setRadius(10.f);
        healthShape->setPosition(updatedxPos, 70.f);
        healthBar.push_back(healthShape);

        updatedxPos += 20.f;
    }
}




