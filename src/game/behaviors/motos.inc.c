void s_motos_hand(void)
{

//	struct Object *firep;
 //   struct Object *parent = o->parentObj;
//    obj_copy_pos(o, parent);
	o->oParentRelativePosX = 100.0f;
	o->oParentRelativePosY = 0.0f;
	o->oParentRelativePosZ = 150.0f;
	o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;

	switch (o->parentObj->oMotosUnk88 ){
	 	case	0:
			break;
		case	1:
			obj_set_gfx_pos_at_obj_pos(gMarioObject, o);
			break;
		case	2:
            gMarioObject->oInteractStatus |=
                (INT_STATUS_MARIO_UNK2 + INT_STATUS_MARIO_UNK6); 
			gMarioStates[0].forwardVel = 50.0f;
			o->parentObj->oMotosUnk88 = 0;
			break;
	}



//	if (o->parentObj->oMotosUnk88 != 0){
//		o->parentObj->oMotosUnk88 = 0;
//	 	firep = spawn_object(o, MODEL_UNKNOWN_7D, bhvUnusedParticleSpawn);
//		firep->oForwardVel = 40.0f;
//		firep->oVelY = 20.0f;
//		firep->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
//	}


}

int s_ai_pitch(s32 angle, f32 dist)
{

	if ( (cur_obj_rotate_yaw_toward(o->oAngleToMario,angle)) && (o->oDistanceToMario < dist) ) 
	return TRUE;
	else																	  return FALSE;
	
}

void bhv_motos_anchor_mario_loop(void) {
    common_anchor_mario_behavior(150.0f, 100.0f, 64);
}

void motos_wait(void)
{
    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;
	cur_obj_init_animation_with_sound(8);

	if ( o->oDistanceToMario < 1000 )	o->oAction = 1;

}

void motos_player_search(void)
{
	s32 sp1C = gGlobalTimer;
	if ((sp1C & 14) == 0) {
cur_obj_play_sound_2(SOUND_OBJ_BULLY_WALKING);
}

	cur_obj_init_animation_with_sound(9);
	o->oForwardVel = 2.0f;
	cur_obj_rotate_yaw_toward(o->oAngleToMario,300);

	if ( o->oInteractStatus & INT_STATUS_GRABBED_MARIO){
		o->oAction = 2;
	 	o->oMotosUnk88 = 1;
	}


}


void motos_player_carry(void)
{

	cur_obj_init_animation_with_sound(3);
	if ( cur_obj_check_if_near_animation_end() )	o->oAction = 5;

}

void motos_player_pitch(void){

	o->oForwardVel = 0.0f;
	cur_obj_init_animation_with_sound(6);
	if ( cur_obj_check_anim_frame(14) ){
		o->oMotosUnk88 = 2;		/* nageru shyn kan	*/
		o->oMotosUnk100 = 10;		/* hit time wait!!	*/ //Despite what it says, it doesn't work
	}
	if ( cur_obj_check_if_near_animation_end() ){
		o->oAction = 0;
		o->oInteractStatus &= ~(INT_STATUS_GRABBED_MARIO);
	}

}

void motos_carry_start(void)
{
	cur_obj_init_animation_with_sound(3);
	if ( cur_obj_check_if_near_animation_end() ){
		if ( s_ai_pitch(0x200,500) ) o->oAction = 5;
		else			   			 o->oAction = 5;
	}		

}

void motos_carry_run(void)
{
	s32 sp1C = gGlobalTimer;
	o->oForwardVel = 5.0f;
	if ((sp1C & 4) == 0) {
cur_obj_play_sound_2(SOUND_ACTION_METAL_STEP);
}
	cur_obj_init_animation_with_sound(2);
	if ( s_ai_pitch(0x200,500) )  o->oAction = 3;
	else			   			  o->oAction = 5;

}

void motos_pitch(void)
{
	o->oForwardVel = 0.0f;
	cur_obj_init_animation_with_sound(6);

	if ( cur_obj_check_anim_frame(14) ){
		o->oMotosUnk88 = 0;
	}
	if ( cur_obj_check_if_near_animation_end() )	
	o->oAction = 0;

}

void motos_fly(void)
{
//   o->oForwardVel = 5.0f;
	cur_obj_init_animation_with_sound(5);
		if ((gCurrLevelNum == LEVEL_SL) & (o->oPosY < 1050.0f)) {
							cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);     
			o->oHealth--;
			o->oPosY = o->oHomeY; //This is a horrible way of making motos return to it's home
			o->oPosX = o->oHomeX;
			o->oPosZ = o->oHomeZ;
			if (o->oHealth) 
                o->oAction = 8;
            if (o->oHealth == 0) 
                o->oAction = 10;
	}
		if (o->oFloor->type == SURFACE_BURNING) {
							cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);     
			o->oHealth--;
			o->oPosY = o->oHomeY;
			o->oPosX = o->oHomeX;
			o->oPosZ = o->oHomeZ;
			if (o->oHealth) 
                o->oAction = 8;
            if (o->oHealth == 0) 
                o->oAction = 10;
	}
	if ( o->oMoveFlags & OBJ_MOVE_LANDED ) {
//	cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);      
	
//	cur_obj_init_animation_with_sound(4);
	o->oAction = 8;
	}

}

void motos_recover(void) {
//   o->oForwardVel = 5.0f;
    o->oForwardVel = 2.0f;

	cur_obj_init_animation_with_sound(4);
if ( cur_obj_check_anim_frame(14) )	
	o->oAction = 1;
}
	
void motos_recover2(void) {
    struct Surface *floor = cur_obj_update_floor_height_and_get_floor();
    o->oFloor = floor;
//   o->oForwardVel = 5.0f;
         	o->oForwardVel = 0.0f;
	cur_obj_init_animation_with_sound(7);
			if ((gCurrLevelNum == LEVEL_SL) & (o->oPosY < 1050.0f)) { //Repeat for good measure
							cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);     
			o->oHealth--;
			o->oPosY = o->oHomeY; //This is a horrible way of making motos return to it's home
			o->oPosX = o->oHomeX;
			o->oPosZ = o->oHomeZ;
			if (o->oHealth) 
                o->oAction = 1;
            if (o->oHealth == 0) 
                o->oAction = 10;
	}
		if (o->oFloor->type == SURFACE_BURNING) {
							cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);     
			o->oHealth--;
			o->oPosY = o->oHomeY; //This is a horrible way of making motos return to it's home
			o->oPosX = o->oHomeX;
			o->oPosZ = o->oHomeZ;
			if (o->oHealth) 
                o->oAction = 1;
            if (o->oHealth == 0) 
                o->oAction = 10;
	}
//	if (o->oFloor->type != SURFACE_BURNING) {
//		cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);     
o->oAction = 1;
}

void motos_death(void) { 

        create_sound_spawner(SOUND_OBJ_KING_WHOMP_DEATH);

        spawn_mist_particles_variable(0, 0, 200.0f);
        spawn_triangle_break_particles(20, 138, 3.0f, 4);
        cur_obj_shake_screen(SHAKE_POS_SMALL);
		cur_obj_hide();
        cur_obj_become_intangible();
		if (gCurrLevelNum == LEVEL_SL) {
        spawn_default_star(300.0f, 1500.0f, -5335.0f);
		o->oAction = 8;
		}
		else 
        spawn_default_star(3700.0f, 600.0f, -5500.0f);
        o->oAction = 8;
		}
void (*sMotosActions[])(void) = { motos_wait, motos_player_search, motos_player_carry, motos_player_pitch, motos_carry_start, motos_carry_run, motos_pitch, motos_fly, motos_recover, motos_recover2, motos_death};

void motos_main(void)
{
    cur_obj_update_floor_and_walls();
//cur_obj_move_using_fvel_and_gravity();	
	

//	default: rmonpf(("Error objmode motos\n")); }

	    cur_obj_move_standard(-78);							/*	monky moving 	*/
    if (o->oDistanceToMario < 5000.0f)
        cur_obj_enable_rendering();
    else
        cur_obj_disable_rendering();
}

void s_motos(void)
{
    f32 sp2C = 10.0f;
    f32 sp28 = 20.0f;

	cur_obj_scale(2.0f);

    o->oInteractionSubtype |= INT_SUBTYPE_GRABS_MARIO;

	switch (o->oAction) {
	case 0:
	motos_wait();
	break;
	case 1:
	motos_player_search();
	break;
	case 2:
	motos_player_carry();
	break;
	case 3:
	motos_player_pitch();
	break;
	case 4:
	motos_carry_start();
	break;
	case 5:
	motos_carry_run();
	break;
	case 6:
	motos_pitch();
	break;
	case 7:
	motos_fly();
	break;
	case 8:
	motos_recover();
	break;
	case 9:
	motos_recover2();
	break;
	case 10:
	motos_death();
	break;
	}
cur_obj_call_action_function(sMotosActions);
	switch (o->oHeldState) {
        case HELD_FREE:
            motos_main();
            break;
        case HELD_HELD:
            cur_obj_unrender_and_reset_state(8, 1);
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            cur_obj_get_thrown_or_placed(sp2C, sp28, 7);
            break;
	}
    o->oInteractStatus = 0;
//	s_erase_shape(obj_playerdist,2000);
 // cur_obj_become_tangible();
}
