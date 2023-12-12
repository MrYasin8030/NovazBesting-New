static bool wakeup{ false };
static bool sex{ false };
vector2 window_pos1{ 50, 50 };
vector2 window_pos{ 50, 50 }, mouse_pos, next_item_pos;
vector2 window_sizemain;
vector2 old_mouse_pos;
bool mouse_state, insert_state;
rust::classes::EventType menu_event;
bool old_mouse_state, old_insert_state;

vector2 widget_mouse_pos, old_widget_mouse_pos;
bool widget_state, old_widget_state;
float color_picker_alpha;
bool is_menu_open{ true };
bool interacting;
bool is_mouse_in_box(const vector2& pos1, const vector2& pos2) {
	if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
		return false;

	if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
		return false;

	return true;
}

bool window(wchar_t* title, const vector2& pos, const vector2& window_size, const vector2& wi_size, bool always_open)
{
	if (!sex) {
		window_pos = pos;
		window_pos1 = vector2(900, 300);
		sex = true;
	}
	auto mouse = get_mousePosition();
	auto width = unity::get_width();
	auto height = unity::get_height();
	window_sizemain = window_size;

	menu_event = gui::methods::get_type(gui::methods::get_current());
	const auto key_code = unity::get_keyCode(gui::methods::get_current());

	insert_state = menu_event == rust::classes::EventType::KeyDown && key_code == rust::classes::KeyCode::Insert;

	mouse_pos.x = get_mousePosition().x;
	mouse_pos.y = unity::get_height() - get_mousePosition().y;
	mouse_state = GetMouseButton(0);
	if (insert_state && !old_insert_state && !always_open)
		is_menu_open = !is_menu_open;

	if (is_menu_open)
	{
		gui::menu_alpha = min(gui::menu_alpha + 7, 255);
	}

	if (!is_menu_open) {
		gui::menu_alpha = max(gui::menu_alpha - 7, 0);
		if (gui::menu_alpha == 0)
			return false;
	}
	if (is_mouse_in_box({ window_pos.x, window_pos.y }, { window_pos.x + window_size.x, window_pos.y + 20 }) && mouse_state && gui::main_menu_open) {
		window_pos.x += mouse_pos.x - old_mouse_pos.x;
		window_pos.y += mouse_pos.y - old_mouse_pos.y;
	}

	if (menu_event == rust::classes::EventType::Repaint)
	{
		float pos_y = 50;
		float xs = unity::get_width() / 2, ys = unity::get_height() / 2;
		//FullRect(rust::classes::Rect{ xs - 40, ys - 480, 80, 13 }, gui222::Color(30, 30, 30, menu_alpha));
		//outline_box({ xs - 40, ys - 480 }, { 80, 10 }, gui222::Color(61, 61, 61, menu_alpha));

		gui::fill_box2({ window_pos.x, window_pos.y, window_size.x + 1, window_size.y + 1 }, { 24, 24, 24, 255 });// //Задний фон
		//gui::fill_box2({ window_pos.x, window_pos.y, window_size.x + 1, 15 }, { 30, 30, 30, menu_alpha });

		gui::fill_box2({ window_pos.x + 15 , window_pos.y + 15, window_size.x - 30, 40 }, { 30, 30, 30, 255 }); // Для табов
		if (Vars::User::activetab == 0) {
			gui::fill_box2({ window_pos.x + 15 , window_pos.y + 65, 570, 345 }, { 30, 30, 30, 255 }); // Для суб табов визул
		}
		if (Vars::User::activetab == 1) {
			gui::fill_box2({ window_pos.x + 15 , window_pos.y + 65, 570 , 345 }, { 30, 30, 30, 255 }); // Для суб табов миск

		}
		if (Vars::User::activetab == 2) {
			gui::fill_box2({ window_pos.x + 15 , window_pos.y + 65, 570 , 345 }, { 30, 30, 30, 255 }); // Для суб табов визул
		}
		if (Vars::User::activetab == 3) {
			gui::fill_box2({ window_pos.x + 15 , window_pos.y + 65, 570 , 345 }, { 30, 30, 30, 255 }); // Для суб табов миск
		}
		///////
	   /* gui::fill_box2({ window_pos.x, window_pos.y - 20, window_size.x, 20 }, { 30, 30, 30, 255 });

		gui::Text(window_pos.x + 3, window_pos.y - 20, window_size.x / 2, 20, title, { 103, 149, 232, 255 }, false, true, 11.f);
		gui::Text(window_pos.x + 318, window_pos.y - 20, window_size.x / 2, 20, titletwo, { 103, 149, 232, 255 }, false, true, 11.f);*/

	}
	return true;
}
int table = 0;

void tab_Cc(const wchar_t* name, int id, vector2 tab_size = vector2(90.f, 30.f)) {
	if (menu_event == rust::classes::EventType::Repaint) {
		if (is_mouse_in_box({ window_pos.x + (id * 150) + 35, window_pos.y + 20 }, { window_pos.x + (id * 150) + 35 + tab_size.x , window_pos.y + 20.f + tab_size.y }) && mouse_state)
			Vars::User::activetab = id;
	}

	if (menu_event == rust::classes::EventType::Repaint) {
		//vertical_line(vector2(window_pos.x + tab_size.x, window_pos.y + (id * 30) + 35.f ), tab_size.y, id == Vars::User::activetab ? gui222::Color(0, 0, 252, menu_alpha) : gui222::Color(52, 52, 52, menu_alpha));
		//	gui::fill_box2({ window_pos.x + (id * 100) + 35, window_pos.y + 20, tab_size.x , tab_size.y }, id == Vars::User::activetab ? gui222::Color(103, 149, 232, menu_alpha) : gui222::Color(52, 52, 52, menu_alpha));
		//	outline_box({ window_pos.x + (id * 100) + 35, window_pos.y + 20 }, {tab_size.x, tab_size.y}, gui222::Color(61, 61, 61, menu_alpha));
		gui::Text(window_pos.x + (id * 150) + 35, window_pos.y + 20, tab_size.x, tab_size.y, (name), id == Vars::User::activetab ? Color(255, 255, 255, 255) : Color(52, 52, 52, 255), true, true);
	}
}
  bool combo_clicked = false;

void checkbox(const wchar_t* title, bool& value) {
	if (is_mouse_in_box({ next_item_pos.x - 6, next_item_pos.y }, { next_item_pos.x - 6 + 15, next_item_pos.y + 15 }) && mouse_state && !old_mouse_state && !interacting)
		value = !value;

	if (menu_event == rust::classes::EventType::Repaint)
	{

		if (value)
			gui::fill_box({ next_item_pos.x - 6, next_item_pos.y , 16, 16 }, { 255, 255, 255, 255 });

		gui::outline_box({ next_item_pos.x - 6, next_item_pos.y }, { 16, 16 }, { 52, 52, 52, 255 });
		gui::Text(next_item_pos.x + 15.f, next_item_pos.y - 2, 300, 20, title, { 255, 255, 255, 255 }, false, true);
	}

	next_item_pos.y += 22;
}

void slider(const wchar_t* title, float& value, int min, int max, const wchar_t* suffix)
{
	next_item_pos.x -= 6;

	if (menu_event == rust::classes::EventType::Repaint)
	{
		if (is_mouse_in_box({ next_item_pos.x + 1, next_item_pos.y + 16 }, { next_item_pos.x + 141, next_item_pos.y + 22 }) && mouse_state && !interacting) {
			value = float((old_mouse_pos.x - (next_item_pos.x + 1)) * (max - min) / 140);
		}
		char m_szValue[64];
		wchar_t m_wszValue[64];
		itoass(static_cast<float>(value), m_szValue, 10);
		AnsiToUnicode(m_szValue, m_wszValue);
		gui::Text(next_item_pos.x + 1, next_item_pos.y - 2, 300, 20, title, { 255, 255, 255, gui::menu_alpha }, false, false);

		gui::outline_box({ next_item_pos.x, next_item_pos.y + 16 }, { 140, 7 }, { 61, 61, 61, 255 });
		gui::fill_box2({ next_item_pos.x + static_cast<float>((value * 140) / max) - 4.f, next_item_pos.y + 16, 4, 7 }, { 255,255,255, 255 });
		//gui::fill_box2({ next_item_pos.x + 1, next_item_pos.y + 16, static_cast<float>((value * 140) / max) - 1, 5 }, { 118,124,184, gui::menu_alpha });
		gui::Text(next_item_pos.x + 147, next_item_pos.y + 8, 300, 20, m_wszValue, { 255, 255, 255, gui::menu_alpha }, false, false, 11);
	}

	next_item_pos.x += 6;
	next_item_pos.y += 25;
}

void combobox(const wchar_t* title, const vector2& pos, const vector2& size)
{
	//gui::outline_box({ window_pos.x + pos.x , window_pos.y + pos.y }, { size.x, size.y }, { 61, 61, 61, 255 });

	next_item_pos = { window_pos.x + pos.x + 15, window_pos.y + pos.y + 17 };

}

void end_window() {
	old_insert_state = insert_state;
	old_mouse_pos = mouse_pos;
	old_mouse_state = mouse_state;
}

void apex_menu() {
	gui::init();
	if (local_player)
		gui::tick_time_when_called = local_player->get_last_sent_ticket_time();
 
	auto mouse = get_mousePosition();
	auto width = unity::get_width();
	auto height = unity::get_height();
	menu_event = gui::methods::get_type(gui::methods::get_current());
	float xs = unity::get_width() / 2, ys = unity::get_height() / 2;
	if (menu_event == rust::classes::EventType::KeyDown || menu_event == rust::classes::EventType::KeyUp) {
		rust::classes::KeyCode cur = unity::get_keyCode(gui::methods::get_current());
		if (menu_event == rust::classes::EventType::KeyDown)
			gui::OnKeyDown(cur);
		else
			gui::OnKeyUp(cur);
	}

	 

	if (menu_event == rust::classes::EventType::Repaint) {

		if (vars::weapon::Fov)
			gui::DrawFov(Color(0, 255, 255, 200), vector2(width / 2, height / 2), vars::weapon::aimbotfov);

		if (vars::misc::Crosshair) {
			
				gui::DrawFov(Color(0, 255, 255, 200), vector2(width / 2, height / 2), 2);
		}
		float barv = 200.f;
		if (vars::misc::flyhack_indicator) {
			if (vars::flyhack / vars::max_flyhack >= 3.f) {
				gui::Progbar({ xs - 125,  barv },
					{ 250, 10 },
					vars::flyhack / vars::max_flyhack,
					vars::flyhack / vars::max_flyhack);
			}
			else {
				gui::Progbar({ xs - 125,barv },
					{ 250, 10 },
					vars::flyhack / vars::max_flyhack, 1.f);
			}

			if (vars::hor_flyhack / vars::max_hor_flyhack >= 6.5f) {
				gui::Progbar({ xs - 125, barv + 12 },
					{ 250, 10 },
					vars::hor_flyhack / vars::max_hor_flyhack,
					vars::hor_flyhack / vars::max_hor_flyhack);
			}
			else {
				gui::Progbar({ xs - 125, barv + 12 },
					{ 250, 10 },
					vars::hor_flyhack / vars::max_hor_flyhack, 1.f);
			}
		}
		if (local_player) {
			float bars = 0;
			if (vars::weapon::manipulator &&  unity::GetKey(rust::classes::KeyCode::Mouse4))
				gui::Progbar({ xs - 70, (ys + 15 + (bars++ * 10)) }, { 140, 6 }, vars::desyncTime, 1.0f);
		}
		if (vars::Radar::Enable)
			gui::RenderRadarBackground(vars::Radar::Pos_X, vars::Radar::Pos_Y, vars::Radar::Radar_Size);

		 
		 ESPLoop();
	}
	if (vars::misc::watermark)
	{
		gui::fill_box(rust::classes::Rect{ 10, 6, 80, 16 }, rgba(14.f, 18.f, 24.f, 255));
		gui::outline_box({ 10, 6 }, { 80, 16 }, rgba(249.f, 130.f, 109.f, 255.f));
		gui::fill_box(rust::classes::Rect{ 10, 20, 81, 3 }, rgba(66.f, 182.f, 245.f, 255));
		gui::Label(rust::classes::Rect{ 12, 4, 80, 20 }, _(L"NovazBesting"), Color(1, 1, 1, 1), true, 12); //NovazBesting | Beta
	}
	gui::main_menu_open = window(_(L"123"), { 50, 50 }, { 600, 425 }, { 200, 200 }, false);

	if (gui::main_menu_open)
	{
		tab_Cc(L"Aimbot", 0);
		tab_Cc(L"Visuals", 1);
		tab_Cc(L"Object", 2);
		tab_Cc(L"Misc", 3);
		//tab_Cc(L"Anti-Aim", 4);
		switch (Vars::User::activetab)
		{
		case 0:
			combobox(_(L"Aim"), { 13, 62 }, { 300, 365 });
			{
				checkbox(_(L"pSilent"), vars::weapon::psilent);
				
			
				checkbox(_(L"SimpleAimbot"), vars::aimbot);
				if (vars::aimbot) {
					checkbox(_(L"RecoilControl ystem"), vars::RecoilControlSystem);
					
				}
				checkbox(_(L"Prediction"), vars::Prediction);
				checkbox(_(L"DrawFov"), vars::weapon::Fov);
				slider(_(L"AimDistance"), vars::AimLimitDistance, 0.0f, 300.0f, _(L"%d"));
				slider(_(L"Fov"), vars::weapon::aimbotfov, 0.0f, 300.0f, _(L"%d"));
				

				checkbox(_(L"SilentMelee"), vars::weapon::silent_melee);
			
				checkbox(_(L"Ignoreteam"), vars::weapon::Ignoreteam);
			
				checkbox(_(L"Manipulator(Mouse4)"), vars::weapon::manipulator);
				if (vars::weapon::manipulator) {
					checkbox(_(L"BulletTp"), vars::weapon::bullet_tp);
					checkbox(_(L"ViewAngeles"), vars::visuals::angles);
					
					checkbox(_(L"AutoShoot"), vars::weapon::autoshoot);
					 
				}
			}
			combobox(L"Weapon", { 400, 62 }, { 200,285 });
			{
				checkbox(_(L"Recoil"), vars::weapon::norecoil);
				if (vars::weapon::norecoil) {
					slider(_(L"RecoilX"), vars::weapon::recoilx, 0.0f, 6.f, _(L"%d"));
					 
				}
				checkbox(_(L"NoSpread"), vars::weapon::nospread);
				checkbox(_(L"BigBullet"), vars::weapon::thick_bullet);
				checkbox(_(L"RemoveSway"), vars::weapon::nosway);
				checkbox(_(L"InstantEoka"), vars::weapon::eoka);
				checkbox(_(L"BulletTracers"), vars::weapon::bullet_tracers);
				 
				checkbox(_(L"ForceAutomatic"), vars::weapon::automatic);
				 
				checkbox(_(L"RapidFire"), vars::weapon::rapid_fire);
				checkbox(_(L"CanHoldItems"), vars::misc::attack_on_mountables);
				
				
			}
			
			break;
		case 1:
			combobox(_(L"Aim"), { 13, 62 }, { 300, 365 });
			{
				checkbox(_(L"PlayerBox"), vars::visuals::boxesp);
				if (vars::visuals::boxesp) {
					checkbox(_(L"DefaultBox"), vars::visuals::full_box);
					if (vars::visuals::full_box) {
						vars::visuals::corner_box = false;
						vars::visuals::dbox = false;
					}
					checkbox(_(L"CornerBox"), vars::visuals::corner_box);
					if (vars::visuals::corner_box) {
						vars::visuals::full_box = false;
						vars::visuals::dbox = false;
					}
					checkbox(_(L"3DBox"), vars::visuals::dbox);
					if (vars::visuals::dbox) {
						vars::visuals::full_box = false;
						vars::visuals::corner_box = false;
					}
					checkbox(_(L"FillBox"), vars::visuals::fill_box);
				}
				checkbox(_(L"Nickname"), vars::visuals::nameesp);
				checkbox(_(L"Weapon"), vars::visuals::weaponesp);
				checkbox(_(L"Distance"), vars::visuals::distance);
			
				checkbox(_(L"Healthbar"), vars::visuals::sidehealth);
				
				
				checkbox(_(L"Skeleton"), vars::visuals::skeleton);
				checkbox(_(L"WoundedFlag"), vars::visuals::woundedflag);
				slider(_(L"EspDistance"), vars::PlayerEspDistance, 0.f, 300, _(L"%d"));
					
			}
			combobox(L"Other", { 400, 62 }, { 200,305 });
			{
		 
				checkbox(_(L"Sleepers"), vars::visuals::sleeper_esp);
				checkbox(_(L"NPC"), vars::visuals::npc_esp);
				 
				checkbox(_(L"Crosshair"), vars::misc::Crosshair);
				checkbox(_(L"Chams"), vars::visuals::chams);
				checkbox(_(L"Movement Line"), vars::weapon::movement_line);
				checkbox(_(L"RadarPlayer"), vars::Radar::Enable);
				checkbox(_(L"Handchams"), vars::visuals::hand_chams);
				if (vars::visuals::hand_chams)
				{
					checkbox(_(L"Wireframe"), vars::visuals::shader3);
					checkbox(_(L"Glow"), vars::visuals::shader4);
				}
				

				if (vars::Radar::Enable) {
					slider(_(L"RadarPosX"), vars::Radar::Pos_X, 0.f, 3000.f, _(L"%d"));
					slider(_(L"RadarPosY"), vars::Radar::Pos_Y, 0.f, 2500.f, _(L"%d"));
				}
				checkbox(_(L"RayleighChanger"), vars::misc::rayleigh_changer);
				if (vars::misc::rayleigh_changer) {
					slider(_(L"Rayleigh"), vars::misc::rayleigh, 1.f, 150.f, _(L"%d"));
				}
				checkbox(_(L"MieChanger"), vars::misc::mie_changer);
				if (vars::misc::mie_changer) {
					slider(_(L"MieAmount"), vars::misc::mie, 1.f, 100.f, _(L"%d"));
				}
				checkbox(_(L"BrightnessChanger"), vars::misc::brightness_changer);
				if (vars::misc::brightness_changer) {
					slider(_(L"Brightness Amount"), vars::misc::brightness, 1.f, 50.f, _(L"%d"));
				}
				
			}

			//combobox(L"Local", { 80, 230 }, { 200,150 });
			//{
			////	checkbox(_(L"Hand Chams"), vars::visuals::hand_chams);
			////	if (vars::visuals::hand_chams) {
			////		checkbox(_(L"Field Shader"), vars::visuals::shader2);
			////		checkbox(_(L"Material Shader"), vars::visuals::rgb_hand_chams);
			////		checkbox(_(L"Flat Shader"), vars::visuals::def_hand_chams);
			////		checkbox(_(L"Seethrough Shader"), vars::visuals::null_hand_chams);
			////		checkbox(_(L"Wireframe Shader"), vars::visuals::shader3);
			////		checkbox(_(L"List Shader"), vars::visuals::shader4);
			////	}
			////	checkbox(_(L"Desync Indicator"), vars::visuals::desync_indicator);
			////	checkbox(_(L"Reload Indicator"), vars::misc::reloadcooldown);
			////	checkbox(_(L"Noclip Indicator"), vars::misc::flyhack_indicator);
			////	checkbox(_(L"Bullet Tracers"), vars::weapon::bullet_tracers);
			////	checkbox(_(L"Movement Line"), vars::weapon::movement_line);
			//}
			break;
		case 2:
			combobox(L"Resource & Crate", { 13, 62 }, { 200,200 });
			{
				checkbox(_(L"StoneOre"), vars::visuals::stone_ore);
				checkbox(_(L"MetalOre"), vars::visuals::metal_ore);
				checkbox(_(L"SulfurOre"), vars::visuals::sulfur_ore);
				checkbox(_(L"Hemp"), vars::visuals::cloth);
				checkbox(_(L"Stash"), vars::visuals::stash);
				checkbox(_(L"ShowDistanceResource"), vars::visuals::showDistance_resource);
				if (vars::visuals::showDistance_resource) {
					slider(_(L"ResourceDistance"), vars::visuals::distance_resource, 50.f, 400.f, _(L"%d"));
				}

				
				
				checkbox(_(L"ShowDistance Player"), vars::visuals::showDistance);
				if (vars::visuals::showDistance) {
					slider(_(L"PlayerDistance"), vars::visuals::distance_player, 100.f, 400.f, _(L"%d"));
				}

				
				checkbox(_(L"Airdrop"), vars::visuals::airdrops);
				checkbox(_(L"EliteCrate"), vars::visuals::eliitecrate);
				checkbox(_(L"MilitaryCrate"), vars::visuals::militarcrate);
				checkbox(_(L"HeliCrate"), vars::visuals::helicrate);
				checkbox(_(L"BradleyCrate"), vars::visuals::bradleycrate);
				checkbox(_(L"ShowDistance Crate"), vars::visuals::showDistance_crate);
				if (vars::visuals::distance_crate) {
					slider(_(L"CrateDistance"), vars::visuals::distance_crate, 100.f, 5000.f, _(L"%d"));
				}
			}
			combobox(L"Vehicle&Trap", { 400, 62}, {200,285});
			{
				checkbox(_(L"DroppedItems"), vars::visuals::dropped_items);


				checkbox(_(L"Corpse"), vars::visuals::corpses);
				checkbox(_(L"Helicopter"), vars::visuals::heli_esp);
				checkbox(_(L"Minicopter"), vars::visuals::minicopter);
				checkbox(_(L"ScrapHeli"), vars::visuals::scrap_heli);
				checkbox(_(L"Boat"), vars::visuals::boat);
				
				checkbox(_(L"ShowDistanceVehicle"), vars::visuals::showDistance_vehicle);
				if (vars::visuals::distance_vehicle) {
					slider(_(L"VehicleDistance"), vars::visuals::distance_vehicle, 50.f, 5000.f, _(L"%d"));
				}

				checkbox(_(L"AutoTurret"), vars::visuals::autoturret);
				checkbox(_(L"ShotgunTrap"), vars::visuals::trap);
				checkbox(_(L"Landmine"), vars::visuals::mine);
				checkbox(_(L"FlameTurret"), vars::visuals::flame_turret);
				checkbox(_(L"SAMSite"), vars::visuals::sam_site);
				
				checkbox(_(L"ShowDistanceTrap"), vars::visuals::showDistance_turret);
				if (vars::visuals::distance_turret) {
					slider(_(L"TrapDistance"), vars::visuals::distance_turret, 50.f, 400.f, _(L"%d"));
				}
			}
			break;
		case 3:
			combobox(L"Misc", { 13, 62 }, { 200,200 });
			{
				checkbox(_(L"Always-Sprint"), vars::misc::always_sprint);
				checkbox(_(L"InfinityJump"), vars::misc::infinite_jump);
				checkbox(_(L"Spiderman"), vars::misc::spiderman);
				checkbox(_(L"Jumpshoot"), vars::misc::jump_shoot);
				
			 
				checkbox(_(L"FlyhackIndicator"), vars::misc::flyhack_indicator);
				checkbox(_(L"FlyhackStoper"), vars::misc::flyhack_stop);
				checkbox(_(L"Instantrevive"), vars::misc::instant_revive);
				 
				checkbox(_(L"FakeAdmin"), vars::misc::admin_mode);
				checkbox(_(L"Suicide(P)"), vars::misc::TakeFallDamage);
				checkbox(_(L"DisableRecycler"), vars::misc::norecycler);
				checkbox(_(L"Watermark"), vars::misc::watermark);

				checkbox(_(L"BrightNight"), vars::misc::todsky);
				if (vars::misc::todsky) {
					slider(_(L"Stars Value"), vars::misc::staramount, 50.f, 1000.f, _(L"%d"));
				}
				checkbox(_(L"CustomTime"), vars::visuals::Day);
				if (vars::visuals::Day) {
					slider(_(L"TimeValue"), vars::visuals::DayTime, 0.f, 12.f, _(L"%d"));
				}
				combobox(L"Other", { 400, 62 }, { 200,305 });
				{
					checkbox(_(L"CustomFOV"), vars::misc::playerfovtoggle);
					if (vars::misc::playerfovtoggle) {
						slider(_(L"FovValue"), vars::misc::playerfov, 0.0f, 160.0f, _(L"%d"));
					}
					checkbox(_(L"ZoomFOV(Z)"), vars::misc::zoomtoggle);
					checkbox(_(L"Aspectratio"), vars::misc::aspectration);
					if (vars::misc::aspectration)
					{
						slider(_(L"Value"), vars::misc::aspects, 0.0f, 4000.0f, _(L"%d"));
					}

					checkbox(_(L"AutoFarmTree"), vars::misc::AutoFarmTree);
					checkbox(_(L"AutoFarmOre"), vars::misc::AutoFarmOre);
					checkbox(_(L"AutoFarmBot"), vars::misc::AutoFarmBot);
					checkbox(_(L"AntiAim"), vars::misc::spinbot);
					
					checkbox(_(L"NoCollision"), vars::misc::no_playercollision);
					checkbox(_(L"LongNeck[Y]"), vars::misc::eyeoffset);
					 
				}
			}
			 
			 
			break;
		
		}
	}
	end_window();
	return;
}