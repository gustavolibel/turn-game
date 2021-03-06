﻿/**============================================================
Created in 06/16 by Gabriel Silva e Gustavo Cordeiro - Version 1
=============================================================**/
#include <stdio.h>
#include <iostream>

#include "screen.h"
#include "mapa.h"
#include "files.h"
#include "hero.h"
#include "menu.h"

#include "game.h"

using namespace std;

int main(int argc, char **argv){
    //initialize allegro and the all game
    Game *game = new Game;
    if(game->initialize())//Error
        return -1;
    //events
    ALLEGRO_EVENT event;
    while(true){
        event = game->wait_event();
        //Event of time, defined by FPS
        if(event.type == ALLEGRO_EVENT_TIMER)
            game->draw_update();
        //mouse move
        else if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
            game->move_mouse(event.mouse.x,event.mouse.y);
        //mouse click
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            //copy mouse position
            Pixel_Point pixel = game->get_mouse_pixel();
            //in map, not menu options
            if(pixel.y>BAR_OPTIONS){
                //find the tile click
                Point point = find_rec(&pixel);
                game->tile_click(point);
                if(game->finish())
                    break;
            }
            //in menu, not map
            else{
                //if next turn is press
                if(game->menu_click(pixel))
                    game->next_turn();
            }
        }
        //mouse is depress
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            game->depress();
        //keyboard is depress
        else if (event.type == ALLEGRO_EVENT_KEY_UP){
            //space -> next turn
            if(event.keyboard.keycode==ALLEGRO_KEY_SPACE)
                game->next_turn();
            //p-> pause\play music
            else if(event.keyboard.keycode==ALLEGRO_KEY_P)
                game->play_pause_music();
            //Esc -> exit game
            else if(event.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                break;
        }
        //if press in X (close)
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
    }
    delete game;
    return 0;
}
