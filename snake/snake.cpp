
#include <vector>

struct snake_struct {

    int direction ;
    int step ;
    int speed ;
    int wait ;

    vector< int > body_x ;
    vector< int > body_y ;

} ;

snake_struct snake ;

//////////////////////////////////////////////////////////////////////////////

void snake_setup( ) {

    snake.body_x.push_back( WINDOW_WIDTH / 2 ) ;
    snake.body_y.push_back( WINDOW_HEIGHT / 2 ) ;

    snake.direction = 0 ;
    snake.step = 10 ;
    snake.speed = 10 ;
    snake.wait = snake.speed ;

}

//////////////////////////////////////////////////////////////////////////////

void snake_draw( ) {

    gfx_color_set( 0 , 255 , 0 ) ;
    gfx_rectfill_draw( snake.body_x.at( 0 ) , snake.body_y.at( 0 ) , snake.step , snake.step ) ;

}

//////////////////////////////////////////////////////////////////////////////

void snake_move( ) {

    if(snake.wait>0) {
        snake.wait--;
        return;
    }

    snake.wait=snake.speed;

    switch( snake.direction ) {

        case 0:
            snake.body_y[ 0 ] -= snake.step ;
            break;
        case 1:
            snake.body_x[ 0 ] += snake.step ;
            break;
        case 2:
            snake.body_y[ 0 ] += snake.step ;
            break;
        case 3:
            snake.body_x[ 0 ] -= snake.step ;
            break;

    }

    if( snake.body_y[ 0 ] < 0 ) snake.body_y[ 0 ] += WINDOW_HEIGHT ;
    if( snake.body_y[ 0 ] >= WINDOW_HEIGHT ) snake.body_y[ 0 ] -= WINDOW_HEIGHT ;

    if( snake.body_x[ 0 ] < 0 ) snake.body_x[ 0 ] += WINDOW_WIDTH ;
    if( snake.body_x[ 0 ] >= WINDOW_WIDTH ) snake.body_x[ 0 ] -= WINDOW_WIDTH ;

}


void snake_turn_clockwise( ) {

    snake.direction++ ;
    if( snake.direction==4) snake.direction=0;

}

void snake_turn_anticlockwise( ) {

    snake.direction-- ;
    if( snake.direction == -1 ) snake.direction = 3 ;

}

//////////////////////////////////////////////////////////////////////////////

void snake_loop( ) {

    snake_draw( ) ;
    
    snake_move( ) ;
    snake_move( ) ;
    snake_move( ) ;

}

