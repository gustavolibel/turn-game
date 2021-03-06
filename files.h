#define MAX_SOUNDS 100
#define IMGS_ANIMATE 10
#define DAMAGE_FRAMES_DRAW 2

//files sound
#define MUSIC1 "bin/sounds/Trisection.ogg"
#define BUTTON_CLICK "bin/sounds/button.ogg"
#define WIN "bin/sounds/victory.ogg"
#define FIRE_BOW "bin/sounds/bow-puny-fire.ogg"
#define FIRE_BOW_MISS "bin/sounds/bow-puny-fire-miss.ogg"
#define LIGHTNING "bin/sounds/lightning.ogg"
#define LIGHTNING_MISS "bin/sounds/lightning-miss.ogg"
#define SLASH "bin/sounds/axe.ogg"
#define SLASH_MISS "bin/sounds/miss-3.ogg"
#define DIE "bin/sounds/human-die-3.ogg"
#define DIRT_SOUND "bin/sounds/footstep-dirt-08.ogg"
#define WATER_SOUND "bin/sounds/footstep-water-05.ogg"
#define GRASS_SOUND "bin/sounds/footstep-dirt-05.ogg"
#define BRIDGE_SOUND "bin/sounds/footstep-wood.ogg"
#define DOOR_SOUND "bin/sounds/footstep-door.ogg"
#define MORNING_SOUND "bin/sounds/morning.ogg"
#define NIGHT_SOUND "bin/sounds/night.ogg"

//files images
#define ARCHER_BLUE "bin/imgs/archer_blue.png"
#define ARCHER_RED "bin/imgs/archer_red.png"
#define MAGE_RED "bin/imgs/mage_red.png"
#define MAGE_BLUE "bin/imgs/mage_blue.png"
#define SOLDIER_BLUE "bin/imgs/soldier_blue.png"
#define SOLDIER_RED "bin/imgs/soldier_red.png"
#define TOWER_BLUE "bin/imgs/tower_blue.png"
#define TOWER_RED "bin/imgs/tower_red.png"
#define HOUSE1_RED "bin/imgs/house1_red.png"
#define HOUSE1_BLUE "bin/imgs/house1_blue.png"
#define HOUSE2_RED "bin/imgs/house2_red.png"
#define HOUSE2_BLUE "bin/imgs/house2_blue.png"
const char MAGE_ATTACK[IMGS_ANIMATE][MAX_TEXT]= {{"bin/imgs/lightning1.png"},{"bin/imgs/lightning2.png"},{"bin/imgs/lightning3.png"},{"bin/imgs/lightning4.png"},{"bin/imgs/lightning5.png"},{"bin/imgs/lightning6.png"},{"bin/imgs/lightning5.png"},{"bin/imgs/lightning6.png"},{"bin/imgs/lightning5.png"},{"bin/imgs/lightning6.png"}};
const char ARCHER_ATTACK[IMGS_ANIMATE][MAX_TEXT]= {{"bin/imgs/fire_arrow1.png"},{"bin/imgs/fire_arrow2.png"},{"bin/imgs/fire_arrow3.png"},{"bin/imgs/fire_arrow4.png"},{"bin/imgs/fire_arrow5.png"},{"bin/imgs/fire_arrow6.png"},{"bin/imgs/fire_arrow7.png"},{"bin/imgs/fire_arrow8.png"},{"bin/imgs/fire_arrow9.png"},{"bin/imgs/fire_arrow10.png"}};
const char SOLDIER_ATTACK[IMGS_ANIMATE][MAX_TEXT]= {{"bin/imgs/slash1.png"},{"bin/imgs/slash2.png"},{"bin/imgs/slash3.png"},{"bin/imgs/slash4.png"},{"bin/imgs/slash4.png"},{"bin/imgs/slash4.png"},{"bin/imgs/slash4.png"},{"bin/imgs/slash4.png"},{"bin/imgs/slash4.png"},{"bin/imgs/slash4.png"}};
const char SOLDIER_ATTACK_UP[IMGS_ANIMATE][MAX_TEXT]= {{"bin/imgs/slash21.png"},{"bin/imgs/slash22.png"},{"bin/imgs/slash23.png"},{"bin/imgs/slash24.png"},{"bin/imgs/slash24.png"},{"bin/imgs/slash24.png"},{"bin/imgs/slash24.png"},{"bin/imgs/slash24.png"},{"bin/imgs/slash24.png"},{"bin/imgs/slash24.png"}};
#define TARGET "bin/imgs/target.png"
#define TARGET2 "bin/imgs/target2.png"
#define MAPA "bin/imgs/map.png"
#define MAPA_FRONT "bin/imgs/map_front.png"
#define SUN "bin/imgs/sun.png"
#define MOON "bin/imgs/moon.png"
#define CURSOR "bin/imgs/cursor.png"
#define VICTORY "bin/imgs/victory.png"
const char BUTTON[2][MAX_TEXT]={{"bin/imgs/button1.png"},{"bin/imgs/button2.png"}};
const char MENU[2][MAX_TEXT]={{"bin/imgs/menu.png"},{"bin/imgs/menu_clear.png"}};

using namespace irrklang;
// link with irrKlang.dll
//#pragma comment(lib, "irrKlang.lib")


class Sounds{
    ISoundEngine* engine;
    irrklang::ISound* snd;
    bool musicState;
public:
    Sounds(){
        musicState=true;
    }
    int initialize (){
        // start the sound engine with default parameters
        engine = createIrrKlangDevice();
        if (!engine){
            printf("Could not startup engine of irrKlang\n");
            return -1; // error starting up the engine
        }
        //music initialize
        snd = engine->play2D(MUSIC1,true,musicState);
        return 0;
    }
    ~Sounds(){
        // delete engine
        engine->drop();
    }
    //play and pause the music
    void play_pause_music(){
        musicState=!musicState;
        snd->setIsPaused(musicState);
    }
    //play the sound defined by "name"
    void play(string name){
        if(!name.compare("button"))
            engine->play2D(BUTTON_CLICK);
        else if(!name.compare("walk dirt"))
            engine->play2D(DIRT_SOUND);
        else if(!name.compare("walk grass"))
            engine->play2D(GRASS_SOUND);
        else if(!name.compare("walk water"))
            engine->play2D(WATER_SOUND);
        else if(!name.compare("walk bridge"))
            engine->play2D(BRIDGE_SOUND);
        else if(!name.compare("walk house"))
            engine->play2D(DOOR_SOUND);
        else if(!name.compare("fire bow"))
            engine->play2D(FIRE_BOW);
        else if(!name.compare("fire bow miss"))
            engine->play2D(FIRE_BOW_MISS);
        else if(!name.compare("lightning"))
            engine->play2D(LIGHTNING);
        else if(!name.compare("lightning miss"))
            engine->play2D(LIGHTNING_MISS);
        else if(!name.compare("slash"))
            engine->play2D(SLASH);
        else if(!name.compare("slash miss"))
            engine->play2D(SLASH_MISS);
        else if(!name.compare("die"))
            engine->play2D(DIE);
        else if(!name.compare("morning"))
            engine->play2D(MORNING_SOUND);
        else if(!name.compare("night"))
            engine->play2D(NIGHT_SOUND);
        else if(!name.compare("victory"))
            engine->play2D(WIN);
        else
            cout << "Failed to play \"" << name << "\" sound\n";
    }
    //play specific sound of class defined by name
    void play(Class _class, string name){
        if(!name.compare("attack")){
            if(_class==MAGE)
                play("lightning");
            else if (_class==ARCHER)
                play("fire bow");
            else if (_class==SOLDIER)
                play("slash");
        }
        if(!name.compare("attack miss")){
            if(_class==MAGE)
                play("lightning miss");
            else if (_class==ARCHER)
                play("fire bow miss");
            else if (_class==SOLDIER)
                play("slash miss");
        }
    }
    //play specific sound of class defined by terrain
    void play(Terrain terrain,int number=0){
        if(terrain == DIRT)
            play("walk dirt");
        else if(((terrain == HOUSE1)||(terrain == HOUSE2))&&(number==0))
            play("walk bridge");
        else if(((terrain == HOUSE1)||(terrain == HOUSE2))&&(number==1))
            play("walk house");
        else if(terrain == GRASS)
            play("walk grass");
        else if(terrain == WATER)
            play("walk water");
        else if(terrain == BRIDGE)
            play("walk bridge");
    }
    //play specific sound of change the period
    void play(Period period){
        if(period==MORNING)
            play("morning");
        else if(period==NIGHT)
            play("night");
    }
};

//files of image
class Animate{
    Image *heroSoldierRed;
    Image *heroSoldierBlue;
    Image *heroMageRed;
    Image *heroMageBlue;
    Image *imgMageAttack[IMGS_ANIMATE];
    Image *imgArcherAttack[IMGS_ANIMATE];
    Image *imgSoldierAttack[IMGS_ANIMATE];
    Image *imgSoldierAttackUp[IMGS_ANIMATE];
    Image *heroArcherRed;
    Image *heroArcherBlue;
    Image *towerRed;
    Image *towerBlue;
    Image *house1Red;
    Image *house1Blue;
    Image *house2Red;
    Image *house2Blue;
    Image *imgTarget;
    Image *imgTarget2;
    Image *imgMap;
    Image *imgMapFront;
    Image *sun;
    Image *moon;
    Image *imgCursor;
    Image *imgvictory;
    Image *button[2];
    Image *menu[2];
public:
    Animate(){
        //allocate all images
        heroSoldierBlue = new Image(SOLDIER_BLUE);
        heroSoldierRed = new Image(SOLDIER_RED);
        heroMageBlue = new Image(MAGE_BLUE);
        heroMageRed = new Image(MAGE_RED);
        for(int i=0;i<IMGS_ANIMATE;i++){
            imgMageAttack[i] = new Image(MAGE_ATTACK[i]);
            imgArcherAttack[i] = new Image(ARCHER_ATTACK[i]);
            imgSoldierAttack[i] = new Image(SOLDIER_ATTACK[i]);
            imgSoldierAttackUp[i] = new Image(SOLDIER_ATTACK_UP[i]);
        }
        heroArcherBlue = new Image(ARCHER_BLUE);
        heroArcherRed = new Image(ARCHER_RED);
        towerBlue = new Image(TOWER_BLUE);
        towerRed = new Image(TOWER_RED);
        house1Red = new Image(HOUSE1_RED);
        house1Blue = new Image(HOUSE1_BLUE);
        house2Red = new Image(HOUSE2_RED);
        house2Blue = new Image(HOUSE2_BLUE);
        imgTarget = new Image(TARGET);
        imgTarget2 = new Image(TARGET2);
        imgMap = new Image(MAPA);
        imgMapFront = new Image(MAPA_FRONT);
        sun = new Image(SUN);
        moon = new Image(MOON);
        imgCursor = new Image(CURSOR);
        imgvictory = new Image(VICTORY);
        button[0] = new Image(BUTTON[0]);
        button[1] = new Image(BUTTON[1]);
        menu[0] = new Image(MENU[0]);
        menu[1] = new Image(MENU[1]);
    }
    ~Animate(){
        //deallocate all images
        delete heroSoldierRed;
        delete heroSoldierBlue;
        delete heroMageRed;
        delete heroMageBlue;
        for(int i=0;i<IMGS_ANIMATE;i++){
            delete imgMageAttack[i];
            delete imgArcherAttack[i];
            delete imgSoldierAttack[i];
            delete imgSoldierAttackUp[i];
        }
        delete heroArcherRed;
        delete heroArcherBlue;
        delete towerBlue;
        delete towerRed;
        delete house1Red;
        delete house1Blue;
        delete house2Red;
        delete house2Blue;
        delete imgTarget;
        delete imgTarget2;
        delete imgMap;
        delete imgMapFront;
        delete sun;
        delete moon;
        delete imgCursor;
        delete imgvictory;
        delete button[0];
        delete button[1];
        delete menu[0];
        delete menu[1];
    }
    //return image
    Image *get_image(string name){
        if(!name.compare("map"))
            return imgMap;
        else if(!name.compare("map front"))
            return imgMapFront;
        else if(!name.compare("cursor"))
            return imgCursor;
        else if(!name.compare("target"))
            return imgTarget;
        else if(!name.compare("target2"))
            return imgTarget2;
        else if(!name.compare("house1 red"))
            return house1Red;
        else if(!name.compare("house1 blue"))
            return house1Blue;
        else if(!name.compare("house2 red"))
            return house2Red;
        else if(!name.compare("house2 blue"))
            return house2Blue;
        else if(!name.compare("sun"))
            return sun;
        else if(!name.compare("moon"))
            return moon;
        else if(!name.compare("victory"))
            return imgvictory;
        else if(!name.compare("button"))
            return button[0];
        else if(!name.compare("button press"))
            return button[1];
        else if(!name.compare("menu"))
            return menu[0];
        else if(!name.compare("menu clear"))
            return menu[1];
        else{
            cout << "Failed to open \"" << name << "\" image\n";
            return NULL;
        }
    }
    //return the bitmap of Class and Team defined
    Image *get_image(Class _class, Team team){
        if(_class==MAGE&&team==ONE)
            return heroMageBlue;
        else if(_class==MAGE&&team==TWO)
            return heroMageRed;
        else if(_class==SOLDIER&&team==ONE)
            return heroSoldierBlue;
        else if(_class==SOLDIER&&team==TWO)
            return heroSoldierRed;
        else if(_class==ARCHER&&team==ONE)
            return heroArcherBlue;
        else if(_class==ARCHER&&team==TWO)
            return heroArcherRed;
        else if(_class==TOWER&&team==ONE)
            return towerBlue;
        else if(_class==TOWER&&team==TWO)
            return towerRed;
        else
            return NULL;
    }
    //return image and or position of animation of the class
    Image* animation(Class _class, Pixel_Point* attack,Pixel_Point* defender,int frame, Pixel_Point* imgPosition){
        if(frame>=IMGS_ANIMATE)
            return NULL;
        //if class is a mage
        if(_class==MAGE){
            //set position of image
            imgPosition->x = defender->x;
            imgPosition->y = defender->y-100;
            //return image of animation
            return (imgMageAttack[frame]);
        }
        //if class is a Archer, simulate launching projectile
        //https://en.wikipedia.org/wiki/Trajectory_of_a_projectile
        else if(_class==ARCHER){
            int h, dy;
            //distance of enemies
            int d = defender->x - attack->x;
            //set positionX of image
            int dx = d*(frame)/(IMGS_ANIMATE-1);
            imgPosition->x = attack->x+dx;
            //arrow is up and attacker in below of defender
            if((frame)<(IMGS_ANIMATE/2)&&(defender->y<=attack->y))
                h=attack->y-defender->y+SIZE_TILE;
            //arrow is up and attacker in top of defender
            else if((frame)<(IMGS_ANIMATE/2)&&(defender->y>attack->y))
                h=SIZE_TILE;
            //arrow is down and attacker in top of defender
            else if((frame)>=(IMGS_ANIMATE/2)&&(defender->y<=attack->y))
                h=SIZE_TILE;
            //arrow is down and attacker in top of defender
            else
                h=defender->y-attack->y+SIZE_TILE;
            //launching projectile
            if(d!=0){
                //calculate speed initial in launching projectile
                float sin0 = (float)h/sqrt((d/4)*(d/4)+h*h);
                float cos0 = (float)d/(4*sqrt((d/4)*(d/4)+h*h));
                float tan0 = (float)h*4/d;
                float speed0=(float)sqrt(9.8*d/(2*sin0*cos0));
                dy=(int)(dx*tan0-9.8*(dx/(speed0*cos0))*(dx/(speed0*cos0))/2);
                //set side of arrow
                if(attack->x < defender->x)
                    imgArcherAttack[frame]->side = RIGHT;
                else
                    imgArcherAttack[frame]->side = LEFT;
            }
            //vertical launch
            else{
                float speed0 = sqrt(2*h*9.8);
                float t = speed0*frame*2/(9.8*(IMGS_ANIMATE-1));
                dy=(int)(speed0*t-9.8*t*t/2);
            }
            //set positionY of image
            if(frame<(IMGS_ANIMATE/2))
                imgPosition->y = attack->y-dy;
            else
                imgPosition->y = defender->y-dy;
            //return image of animation
            return (imgArcherAttack[frame]);
        }
        //if class is a Soldier
        else if(_class==SOLDIER){
            //return image of animation
            if(frame>=IMGS_ANIMATE)
                return NULL;
            //set position of image
            imgPosition->x = attack->x+frame*(defender->x-attack->x)/IMGS_ANIMATE;
            imgPosition->y = attack->y+frame*(defender->y-attack->y)/IMGS_ANIMATE;
            //set side of slash
            if(attack->x < defender->x){
                imgSoldierAttack[frame]->side = RIGHT;
                return imgSoldierAttack[frame];
            }
            else if(attack->x > defender->x){
                imgSoldierAttack[frame]->side = LEFT;
                return imgSoldierAttack[frame];
            }
            else if(attack->y > defender->y){
                imgSoldierAttackUp[frame]->side = UP;
                return imgSoldierAttackUp[frame];
            }
            else{
                imgSoldierAttackUp[frame]->side = RIGHT;
                return imgSoldierAttackUp[frame];
            }
        }
        return NULL;
    }
};



