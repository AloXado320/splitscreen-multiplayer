const GeoLayout RCP_HmsEnemyicemotos_basedata_A[] = {
GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 100),
 GEO_OPEN_NODE(),
  GEO_TRANSLATE_NODE(0x00,0,-65,0),
  GEO_OPEN_NODE(),
   GEO_SCALE(0x00, 16384),
    GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 279, 0, NULL),  /* body_sprite(35),*/
	  GEO_OPEN_NODE(),
		GEO_BILLBOARD(),
	    GEO_OPEN_NODE(),
		  GEO_DISPLAY_LIST(LAYER_ALPHA,RCP_icemotos_body),
	  	GEO_CLOSE_NODE(),
	  GEO_CLOSE_NODE(),
      GEO_OPEN_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* chn29(34),*/
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt29_1(29),*/
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 209, 0,0, NULL),  /* chn33(25),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt33_1(13),*/
                  GEO_OPEN_NODE(),
                    GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0,RCP_icemotos_LhandB), /* cube5(1),*/
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 208, 1,0, NULL),  /* chn32(20),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt32_1(14),*/
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0,RCP_icemotos_LhandA), /* cube6(2),*/
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 209, 0,0, NULL),  /* eff29(11),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* R_arm_sprite(3),*/
				  GEO_OPEN_NODE(),
				  		GEO_BILLBOARD(),
						GEO_OPEN_NODE(),
						  GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_icemotos_arm),
						GEO_CLOSE_NODE(),
				  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* chn31(33),*/
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt31_1(30),*/
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 208, 1,0, NULL),  /* chn35(26),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt35_1(15),*/
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0,RCP_icemotos_RhandA), /* cube3(4),*/
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 209, 0,0, NULL),  /* chn37(21),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt37_1(16),*/
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0,RCP_icemotos_RhandB), /* cube4(5),*/
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 209, 0,0, NULL),  /* eff31(12),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* R_arm_sprite(3),*/
				  GEO_OPEN_NODE(),
				    GEO_BILLBOARD(),
				    GEO_OPEN_NODE(),
					  GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_icemotos_arm),
				    GEO_CLOSE_NODE(),
				  GEO_CLOSE_NODE(),
				  GEO_ASM(0, geo_update_held_mario_pos),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE,87, 0,0,NULL), /* chn38(32),*/
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt38_1(27),*/
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE,181, 0,0,NULL), /* jnt38_2(22),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE,71, 0,0,NULL), /* jnt38_3(17),*/
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0,RCP_icemotos_Lfoot), /* cube2(6),*/
                  GEO_CLOSE_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0, NULL), /* L_foot_sprite(7),*/
				  GEO_OPEN_NODE(),
				    GEO_BILLBOARD(),
				    GEO_OPEN_NODE(),
					  GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_icemotos_leg),
				    GEO_CLOSE_NODE(),
				  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE,-87, 0,0, NULL),   /* chn40(31),*/
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt40_1(28),*/
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE,181, 0,0, NULL),   /* jnt40_2(23),*/
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE,71, 0,0, NULL),   /* jnt40_3(18),*/
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0,RCP_icemotos_Rfoot), /* cube7(8),*/
                  GEO_CLOSE_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* R_foot_sprite(9),*/
				  GEO_OPEN_NODE(),
				      GEO_BILLBOARD(),
					  GEO_OPEN_NODE(),
					 	 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_icemotos_leg),
				      GEO_CLOSE_NODE(),
				  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE,0,178,0, NULL),   /* chn41(24),*/
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0,0, NULL),  /* jnt41_1(19),*/
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE,0,0,0,RCP_icemotos_head), /* sphere3(10),*/
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
  GEO_CLOSE_NODE(),
 GEO_CLOSE_NODE(),
GEO_END(),
};