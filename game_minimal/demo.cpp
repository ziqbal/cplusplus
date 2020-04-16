
#include "inc.cpp"


#include <vector>

bool pen_down = false ;
bool flag_record = false ;
int m_x=0 , m_y=0;

vector<pair<int,int>> points;

int game_event_keydown( int key ) {

    // SDLK_RIGHT, SDLK_LEFT etc.

    if( key == SDLK_c ) {

        gfx_pixels_clear( ) ;

    }

    if( key == SDLK_r ) {

        points.clear();

        cout<<"zzz"<<endl;

        flag_record=true;


    }

    if( key == SDLK_p ) {


        int points_size = points.size( ) ;

        if(points_size<2) return(0);

        int ox = WINDOW_WIDTH / 2 ;
        int oy = WINDOW_HEIGHT / 2 ;

        ox=ox;
        oy=oy;

        cout<<m_x<<","<<m_y<<endl;
        for(int i=1;i<points_size;i++){
            int x = m_x+points[i].first-points[0].first;
            int y = m_y+points[i].second-points[0].second;

            if(x<0 || x>=WINDOW_WIDTH) continue;
            if(y<0 || y>=WINDOW_HEIGHT) continue;
            gfx_pixel_set( x , y , 255 , 255 , 255 );

            gfx_pixel_set( ox + ( ox - x )  , y , 255 , 255 , 255 ) ;
            gfx_pixel_set( x , oy + ( oy - y ) , 255 , 255 , 255 ) ;

            gfx_pixel_set( ox + ( ox - x ) , oy + ( oy - y ) , 255 , 255 , 255 ) ;
        }







    }

    return( 0 ) ;

}


int game_event_keyup( int key ) {


    if( key == SDLK_r ) {

        flag_record=false;


    }


    cout << "keyup" << endl ;

    return( 0 ) ;
}

int game_keyboard_state( ) {

    if( state_keyboard[ SDL_SCANCODE_DOWN]){
    } else {
    }

    if( state_keyboard[ SDL_SCANCODE_RETURN ] ) {

        printf( "<RETURN> is pressed.\n" ) ;

    }

    if( state_keyboard[ SDL_SCANCODE_RIGHT ] && state_keyboard[ SDL_SCANCODE_UP ] ) {

        printf( "Right and Up Keys Pressed.\n" ) ;

    }

    return( 0 ) ;

}

int game_event_mousebuttondown( int mouse_button , int mouse_x , int mouse_y ) {

    m_x = mouse_x ;
    m_y = mouse_y ;

    //SDL_BUTTON_LEFT,SDL_BUTTON_RIGHT, or something else like middle button

    if( mouse_button == SDL_BUTTON_LEFT ) {
        pen_down=true;

    int ox = WINDOW_WIDTH / 2 ;
    int oy = WINDOW_HEIGHT / 2 ;

    int x = mouse_x ;
    int y = mouse_y ;

    if(pen_down){
        gfx_pixel_set( x , y , 255 , 255 , 255 );

        gfx_pixel_set( ox + ( ox - x )  , y , 255 , 255 , 255 ) ;
        gfx_pixel_set( x , oy + ( oy - y ) , 255 , 255 , 255 ) ;

        gfx_pixel_set( ox + ( ox - x ) , oy + ( oy - y ) , 255 , 255 , 255 ) ;
    }


        //gfx_pixels_clear( ) ;

    }

    return( 0 ) ;

}
int game_event_mousebuttonup( int mouse_button , int mouse_x , int mouse_y ) {

    m_x = mouse_x ;
    m_y = mouse_y ;
    //SDL_BUTTON_LEFT,SDL_BUTTON_RIGHT, or something else like middle button

    if( mouse_button == SDL_BUTTON_LEFT ) {
        pen_down=false;
        //gfx_pixels_clear( ) ;

    }

    return( 0 ) ;

}

int game_event_mousemotion( int mouse_x , int mouse_y ) {

    m_x = mouse_x ;
    m_y = mouse_y ;

    int ox = WINDOW_WIDTH / 2 ;
    int oy = WINDOW_HEIGHT / 2 ;

    int x = mouse_x ;
    int y = mouse_y ;

    if(flag_record){
        points.push_back(make_pair(mouse_x,mouse_y));
        if(points.size()==1000){
            points.erase(points.begin());
        }
    }

    if(pen_down){
        gfx_pixel_set( x , y , 255 , 255 , 255 );

        gfx_pixel_set( ox + ( ox - x )  , y , 255 , 255 , 255 ) ;
        gfx_pixel_set( x , oy + ( oy - y ) , 255 , 255 , 255 ) ;

        gfx_pixel_set( ox + ( ox - x ) , oy + ( oy - y ) , 255 , 255 , 255 ) ;

    }

    return( 0 ) ;

}

int game_setup( ) {

    return( 0 ) ;

}

int game_loop( ) {

    game_keyboard_state( ) ;

    gfx_color_set( 100 , 250 , 200 );


    int points_size = points.size( ) ;

    if(points_size<2) return(0);

    for(int i=1;i<points_size;i++){
        gfx_line_draw( points[i-1].first , points[i-1].second , points[i].first , points[i].second ) ;
    }

    return( 0 ) ;

}

