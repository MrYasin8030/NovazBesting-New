#pragma once
namespace Vars {
	namespace User {
		float ScreenWidth = 1920;
		float ScreenHeight = 1080;

		bool Panic = false;

		bool MenuOpen = true;
		bool InsertPressed = false;

		int activetab = 0;

		int last_active_id = 0;

		float lastSentTickTime = 0.f;
	}
}
int jitter = 1;
int jitter_speed = 10;
int spin_speed = 70;
int spin = 1;
float travel_t = 0.f;
bool manipulated = false;
bool manipulating = false;
float instatime = 0.f;
 
namespace vars {
	bool manipulated = false;
	namespace keybinds {
		int psilent = 0;
		int aimbot = 0;
		int flywall = 0;
		int silentmelee = 0;
		int autoshoot = 0;
		int manipulator = 0;
		int desync_ok = 0;
		int timescale = 0;
		int silentwalk = 0;
		int suicide = 0;
		int neck = 0;
		int zoom = 0;
		int bullettp = 0;
	};
	namespace stor {
	 
		uintptr_t closestPlayer = NULL;
		bool lock_target = false;

	}
	float PlayerEspDistance = 200.0f;
	float time_since_last_shot = 0.0f;
	float desyncTime = 0.0f;
	float bltp = 0.f;
	bool gongetflyhack = true;
	float flyhack = 0.f;
	float hor_flyhack = 0.f;
	float max_flyhack = 0.f;
	float max_hor_flyhack = 0.f;

	bool aimbot = false;
	bool Prediction = false;
	bool RecoilControlSystem = false;
	float AimLimitDistance = 300.f;

	namespace weapon {
		bool onlyvisible = false;
		bool hitboxhelp = false;
		float testFloat = 0.f;
		bool instakill = false;
		float instatimeshoot = 8.f;
		bool sssss = false;
		float instatime = 0.f;
		bool fast_bullets = false;
		bool Ignoreteam = false;
		bool psilenttelo = false;
		bool psilentheaders = false;
		float recoilx = 0.f;
		float recoily = 0.f;
		float RCSyaw = 0;
		float RCSpitch = 0;
		bool Fov = false;
		bool snaplines = false;
		bool rapid_fire = false;
		bool hitbox_override = false;
		bool magic_bullet = false;
		bool fastshoot = false;
		bool fake_shoot = false;
		float aimbotfov = 100;
		float thickness = 2.0;
		bool random_hitbox = false;
		bool silent_melee = false;
		bool weapon_removals = false;
		bool eoka = false;
		bool fast_bow = false;
		bool psilent = false;
		bool psilentvis = false;
		bool thick_bullet = true;
		bool legit_recoil = false;
		bool ultraBullet = false;
		bool norecoil = false;
		bool nospread = false;
		bool nosway = false;
		bool automatic = false;
		bool bullet_tp = false;
		bool silent_reload = false;
		bool no_projectile_spread = false;
		bool insta_kill = false;
		bool autoshoot = false;
		bool manipulator = false;
		bool bullet_tracers = false;
		bool movement_line = false;
		bool visfatbullet = false;
		float visualslider = 10;
	}

	namespace visuals {
		bool target_tracer = false;
		bool shader3 = false;
		bool esp_boar = false;
		bool ignore_npc = false;
		bool esp_preview = false;
		bool snapliness = false;
		bool esp_bear = false;
		bool esp_wolf = false;
		bool player_flags = true;
		bool shader4 = false;
		bool shader2 = false;
		float barespposx = 450.f;
		bool galaxy = false;
		float barespposy = 960.f;
		bool offscreen_indicator = false;
		bool desync_indicator = false;
		bool angles = true;
		bool skeleton = false;
		bool showDistance_crate = false;
		bool showDistance_turret = false;
		bool showDistance_vehicle = false;
		bool showDistance_resource = false;
		bool showDistance = false;
		bool Backpack = false;
		bool visblcheck = false;
		float distance_resource = 300.f;
		float distance_vehicle = 5000.f;
		float distance_turret = 300.f;
		float distance_crate = 5000.f;
		float distance_player = 300.f;
		bool distance = false;
		bool fill_box = false;
		bool player_esp = false;
		bool rainbow_chams = false;
		bool hotbar_esp = false;
		bool chams = false;
		bool whitechams = false;
		bool hand_chams = false;
		bool noattack = false;
		bool nobobing = false;
		bool nolowing = false;
		bool def_hand_chams = false;
		bool rgb_hand_chams = false;
		bool null_hand_chams = false;
		bool rgb_player_chams = false;
		bool wire_player_chams = false;
		bool trought_player_chams = false;
		bool list_player_chams = false;
		bool def_player_chams = false;
		bool field_player_chams = false;
		bool boxesp = false;
		bool spriteitem = false;
		bool cancer = false;
		bool misc_esp = false;
		bool sleeper_esp = false;
		bool heli_esp = false;
		bool outline = false;
		bool npc_esp = false;
		bool dropped_items = false;
		bool stash = false;
		bool materials = false;
		bool sulfur_ore = false;
		bool stone_ore = false;
		bool metal_ore = false;
		bool weapon = false;
		bool midhealth = false;
		bool midname = false;
		bool traps = false;
		bool minicopter = false;
		bool scrap_heli = false;
		bool boat = false;
		bool rhib = false;
		bool autoturret = false;
		bool trap = false;
		bool mine = false;
		bool flame_turret = false;
		bool bear_trap = false;
		bool sam_site = false;
		bool airdrops = false;
		bool cloth = false;
		bool corpses = false;
		bool tc_esp = false;
		bool raid_esp = false;
		bool hackable_crate_esp = false;
		bool full_box = false;
		bool corner_box = false;
		bool dbox = false;
		bool bottomhealth = false;
		bool steamid = false;
		bool sidehealth = false;
		bool healthbar = false;
		bool nameesp = false;
		bool woundedflag = false;
		bool eliitecrate = false;
		bool militarcrate = false;
		bool helicrate = false;
		bool bradleycrate = false;
		bool weaponesp = false;
		bool vehicle = false;
		bool Day = false;
		float DayTime = 12.f;
	}

	namespace misc {
		bool flyhack_stop = false;
		bool fast_loot = false;
		bool rayleigh_changer = false;
		float rayleigh = 1.f;
		bool flyhack = false;
		bool watermark = true;
		bool Crosshair = true;
		bool mie_changer = false;
		float mie = 1.f;
		bool brightness_changer = false;
		float brightness = 1.f;
		float gravity_modifier = 0.f;
		bool norecycler = false;
		bool aspectration = false;
		float aspects = 1000.f;
		bool DoorKnocker = false;
		bool AutoPickup = false;
		bool AutoFarmOre = false;
		bool AutoFarmTree = false;
		bool stesh_opener = false;
		bool AutoFarmBarrel = false;
		bool reloadcooldown = false;
		bool flyhack_indicator = false;
		bool AutoFarmBot = false;
		bool activ_checkbox = false;
		bool todsky = false;
		float m_idebugcam_speed = 1.f;
		float code_lock_code = 1000;
		bool playerfovtoggle = false;
		float playerfov = 90;
		bool zoomtoggle = false;
		float zoomfov = 10;
		bool Movement = false;
		bool eyeoffset = false;
		bool eyeoffset1 = false;
		bool eyeoffset2 = false;
		bool noclip = false;
		float playereyes = 1.4;
		bool attack_on_mountables = false;
		bool speedhack = false;
		bool hitsound = false;
		float speedhackspeed = 5;
		bool TakeFallDamage = false;
		bool silent_farm = false;
		bool auto_lock = false;
		bool always_sprint = false;
		bool code = false;
		bool jump_shoot = false;
		bool gravity = false;
		bool infinite_jump = false;
		bool fake_lag = false;
		bool brightnight = false;
		float staramount = 1000;
		bool admin_mode = false;
		bool view_offset = false;
		bool instant_med = false;
		bool instant_revive = false;
		bool no_playercollision = false;
		bool spiderman = false;
		int crosshair = 0;
		bool silentwalk = false;
		bool interactive_debug = false;
		bool trollface = false;
		bool spinbot = false;
		bool FarmStoneOre = false;
		bool FarmMetallOre = false;
		bool FarmSulphurOre = false;
		namespace yaw {
			bool roll = false;
			bool backwards = false;
			bool backwards_down = false;
			bool backwards_up = false;
			bool left = false;
			bool left_down = false;
			bool left_up = false;
			bool right = false;
			bool right_down = false;
			bool right_up = false;
			bool jitter = false;
			bool jitter_down = false;
			bool jitter_up = false;
			bool spin = false;
			bool spin_down = false;
			bool spin_up = false;
			bool random = false;
		}
	}


	namespace Radar
	{
		float ActiveSlotPos_X = 63.f;
		float ActiveSlotPos_Y = 315.f;
		bool ActiveSlot = true;



		bool Enable = false;
		bool ShowRadarBackground = false;
		bool ShowRadarStoneOre = false;
		bool ShowRadarMettalOre = false;
		bool ShowRadarSulfureOre = false;



		float Pos_X = 30;
		float Pos_Y = 30;
		float Radar_Size = 200;
		float Radar_Range = 300;
	}
}