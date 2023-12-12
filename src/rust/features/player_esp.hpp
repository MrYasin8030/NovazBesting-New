#pragma once
#include <array>
#include <cstdint>
#include "../../memory/il2cpp.hpp"
#include "../../vars.hpp"
#include "../classes.hpp"
#include "../rust.hpp"
#include "../../gui/render.hpp"


class Color {
public:
	float r;
	float g;
	float b;
	float a;

	Color()
	{
		r = 0;
		g = 0;
		b = 0;
		a = 0;
	}

	Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color GetUnityColor()
	{
		return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}
};

namespace esp {
	float time_last_upgrade = 0.f;
	float rl_time = 0.f;

	uintptr_t client_entities;
	BasePlayer* TargetAimBotPlayer = nullptr;
	VMatrix matrix;
	aim_target best_target = aim_target();

	struct bounds_t {
		float left, right, top, bottom;
	};

	struct rust_str
	{
		char zpad[128];
	};

	bool out_w2s(const Vector& position, vector2& screen_pos) {
		if (!matrix.m) {
			return false;
		}

		vector2 out;
		const auto temp = matrix.transpose();

		auto translation_vector = Vector{ temp[3][0], temp[3][1], temp[3][2] };
		auto up = Vector{ temp[1][0], temp[1][1], temp[1][2] };
		auto right = Vector{ temp[0][0], temp[0][1], temp[0][2] };

		float w = translation_vector.Dot(position) + temp[3][3];

		if (w < 0.098f) {
			return false;
		}

		float x = up.Dot(position) + temp._24;
		float y = right.Dot(position) + temp._14;

		out.x = (static_cast<float>(unity::get_width()) / 2) * (1 + y / w);
		out.y = (static_cast<float>(unity::get_height()) / 2) * (1 - x / w);

		screen_pos = out;

		return true;
	}

	float xs = unity::get_width() / 2, ys = unity::get_height() / 2;

	inline float GetFov(BasePlayer* Entity)
	{

		vector2 ScreenPos;
		if (!out_w2s(Entity->get_bone_transform(48)->get_bone_position(), ScreenPos)) return 1000.f;
		return Calc2D_Dist_2(vector2(unity::get_width() / 2, unity::get_height() / 2), ScreenPos);
	}
	inline float GetGravity(const int ammoid)
	{
		switch (ammoid)
		{
		case 14241751: //fire arrow
			return 1.f;
		case -1234735557: //arrow normal
			return 0.75f;
		case 215754713: //arrow bone
			return 0.75f;
		case -1023065463: //hv arrow
			return 0.5f;
		case 1602646136:
			return 100.f;
		case -2097376851: //nails
			return 0.75f;
		case -1321651331: //5.56 exp
			return 1.25f;
		default:
			return 1.f;
		}
	}

	float GetBulletSpeed()
	{
		switch (local_player->get_active_weapon()->GetID() + local_player->get_active_weapon()->LoadedAmmo())
		{
		case 377132179: // bolt 5.56
			return 656.f;
		case 3300368691: // bolt 5.56 hv
			return 788.f;
		case 266647104: // bolt 5.56 inc
			return 394.f;
		case 2193765803: // bolt 5.56 ex
			return 394.f;
		case -1989533551: // l96 5.56
			return 1125.f;
		case 933702961: // l96 5.56 hv
			return 1350.f;
		case -2100018626: // l96 5.56 inc
			return 675.f;
		case -172899927: // l96 5.56 ex
			return 675.f;
		case -3280745144: // l96 5.56
			return 488.f;
		case -357508632: // l96 5.56 hv
			return 585.f;
		case -3391230219: // l96 5.56 inc
			return 293.f;
		case 1602646136:
			return 100.f;
			
		case -1464111520: // l96 5.56 ex
			return 293.f;
		case 2104286852: // mp5a4 5.56
			return  250.f;
		case -372837868: // mp5a4 5.56 hv
			return 330.f;
		case 1370543430: // mp5a4 5.56 inc
			return 190.f;
		case -1182964415: //m39 5 56
			return 469.f;
		case  1740272097: //m39 hv
			return 563.f;
		case -1293449490: //m39 inc
			return 281.f;
		case 633669209: //m39 exp
			return 281.f;
		case -3023721433: //lr300 5 56
			return 375.f;
		case -100484921: //lr300 hv
			return 450.f;
		case -3134206508: //lr300 inc
			return 225.f;
		case -1207087809: //lr300 exp
			return 225.f;
		case -2116029401: //sar 5 56
			return 380.f;
		case 807207111: //sar hv
			return 450.f;
		case -2226514476: //sar inc
			return 225.f;
		case -299395777: //sar exp
			return 225.f;
		case 334613342: //ak 5 56
			return 375.f;
		case 3257849854: //ak hv
			return 450.f;
		case 224128267: //ak inc
			return 225.f;
		case 2151246966: //ak exp
			return 225.f;
	
		case 2582410286: // smg 5.56
			return  250.f;
		case 105285566: // smg 5.56 hv
			return 330.f;
		case 1848666864: // smg 5.56 inc
			return 180.f;
		case -972644648: //thompson
			return 320.f;
		case -1867233915: //thompson hv
			return 420.f;
		case -1706388070: //thompson inc
			return 235.f;
		case 1435640691: //revolver
			return 300.f;
		case -1041484029: //revolver hv
			return 420.f;
		case 701897269: //revolver inc
			return 235.f;
		case 2159699936: //python
			return 330.f;
		case -317424784: //python hv
			return 430.f;
		case 1425956514: //python inc
			return 225.f;
		case 1604605561: //semi-pistol
			return 300.f;
		case -872519159: //semi-pistol hv
			return 400.f;
		case 870862139: //semi-pistol inc
			return 225.f;
		case -66834942: //m92
			return 330.f;
		case -2543959662: //m92 hv
			return 400.f;
		case -800578364: //m92 inc
			return 225.f;
		case 730496837: //Crossbow
			return 85.f;
		case -1008823712: //Crossbow hv
			return 120.f;
		case 229996464: //Crossbow bone
			return 68.f;
		case 1979474145: //Crossbow fire
			return 60.f;
		case 14241751:
			return 40.f;
		case -350311508: //Compound Bow
			return 55.f;
		case 1907489512: //Compound Bow hv
			return 80.f;
		case 1100178762: //Compound Bow bone
			return 45.f;
		case 1443579727: //Compound Bow fire
			return 40.f;
		case -2425708753:
			return 300.f;
		case -609075129:
			return 275.f;
		case 208844170: //Hunting Bow
			return 55.f;
		case 420514264: //Hunting Bow hv
			return 85.f;
		case 1659334440: //Hunting Bow bone
			return 55.f;
		case 1457821478: //Hunting Bow fire
			return 55.f;
		case -143473650: //Nailgun
			return 55.f;
		default:
			return 100.f;
		}
	}
	//inline float GetGravity(const int ammoid)
	//{
	//	switch (ammoid)
	//	{
	//	case 14241751: //fire arrow
	//		return 1.f;
	//	case -1234735557: //arrow normal
	//		return 0.75f;
	//	case 215754713: //arrow bone
	//		return 0.75f;
	//	case -1023065463: //hv arrow
	//		return 0.5f;
	//	case -2097376851: //nails
	//		return 0.75f;
	//	case -1321651331: //5.56 exp
	//		return 1.25f;
	//	default:
	//		return 1.f;
	//	}
	//}

	//float GetBulletSpeed()
	//{
	//	switch (local_player->get_active_weapon()->GetID() + local_player->get_active_weapon()->LoadedAmmo())
	//	{
	//	case 377132179: // bolt 5.56
	//		return 656.f;
	//	case 3300368691: // bolt 5.56 hv
	//		return 788.f;
	//	case 266647104: // bolt 5.56 inc
	//		return 394.f;
	//	case 2193765803: // bolt 5.56 ex
	//		return 394.f;
	//	case -1989533551: // l96 5.56
	//		return 1125.f;
	//	case 933702961: // l96 5.56 hv
	//		return 1350.f;
	//	case -2100018626: // l96 5.56 inc
	//		return 675.f;
	//	case -172899927: // l96 5.56 ex
	//		return 675.f;
	//	case -3280745144: // l96 5.56
	//		return 488.f;
	//	case -357508632: // l96 5.56 hv
	//		return 585.f;
	//	case -3391230219: // l96 5.56 inc
	//		return 293.f;
	//	case -1464111520: // l96 5.56 ex
	//		return 293.f;
	//	case 2104286852: // mp5a4 5.56
	//		return  240.f;
	//	case -372837868: // mp5a4 5.56 hv
	//		return 320.f;
	//	case 1370543430: // mp5a4 5.56 inc
	//		return 180.f;
	//	case -1182964415: //m39 5 56
	//		return 469.f;
	//	case  1740272097: //m39 hv
	//		return 563.f;
	//	case -1293449490: //m39 inc
	//		return 281.f;
	//	case 633669209: //m39 exp
	//		return 281.f;
	//	case -3023721433: //lr300 5 56
	//		return 375.f;
	//	case -100484921: //lr300 hv
	//		return 450.f;
	//	case -3134206508: //lr300 inc
	//		return 225.f;
	//	case -1207087809: //lr300 exp
	//		return 225.f;
	//	case -2116029401: //sar 5 56
	//		return 375.f;
	//	case 807207111: //sar hv
	//		return 450.f;
	//	case -2226514476: //sar inc
	//		return 225.f;
	//	case -299395777: //sar exp
	//		return 225.f;
	//	case 334613342: //ak 5 56
	//		return 375.f;
	//	case 3257849854: //ak hv
	//		return 450.f;
	//	case 224128267: //ak inc
	//		return 225.f;
	//	case 2151246966: //ak exp
	//		return 225.f;

	//	case 2582410286: // smg 5.56
	//		return  240.f;
	//	case 105285566: // smg 5.56 hv
	//		return 320.f;
	//	case 1848666864: // smg 5.56 inc
	//		return 180.f;
	//	case -972644648: //thompson
	//		return 300.f;
	//	case -1867233915: //thompson hv
	//		return 400.f;
	//	case -1706388070: //thompson inc
	//		return 225.f;
	//	case 1435640691: //revolver
	//		return 300.f;
	//	case -1041484029: //revolver hv
	//		return 400.f;
	//	case 701897269: //revolver inc
	//		return 225.f;
	//	case 2159699936: //python
	//		return 300.f;
	//	case -317424784: //python hv
	//		return 400.f;
	//	case 1425956514: //python inc
	//		return 225.f;
	//	case 1604605561: //semi-pistol
	//		return 300.f;
	//	case -872519159: //semi-pistol hv
	//		return 400.f;
	//	case 870862139: //semi-pistol inc
	//		return 225.f;
	//	case -66834942: //m92
	//		return 300.f;
	//	case -2543959662: //m92 hv
	//		return 400.f;
	//	case -800578364: //m92 inc
	//		return 225.f;
	//	case 730496837: //Crossbow
	//		return 75.f;
	//	case -1008823712: //Crossbow hv
	//		return 120.f;
	//	case 229996464: //Crossbow bone
	//		return 68.f;
	//	case 1979474145: //Crossbow fire
	//		return 60.f;

	//	case -350311508: //Compound Bow
	//		return 55.f;
	//	case 1907489512: //Compound Bow hv
	//		return 80.f;
	//	case 1100178762: //Compound Bow bone
	//		return 45.f;
	//	case 1443579727: //Compound Bow fire
	//		return 40.f;
	//	case 208844170: //Hunting Bow
	//		return 50.f;
	//	case 420514264: //Hunting Bow hv
	//		return 80.f;
	//	case 1659334440: //Hunting Bow bone
	//		return 45.f;
	//	case 1457821478: //Hunting Bow fire
	//		return 40.f;
	//	case -143473650: //Nailgun
	//		return 45.f;
	//	default:
	//		return 100.f;
	//	}
	//}

	Vector ClosestPoint(BasePlayer* player, Vector vec) {
		typedef Vector(__stdcall* CPoint)(BasePlayer*, Vector);
		Vector result = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(player, vec);
		return result;
	}

	inline Vector Prediction(Vector LP_Pos, BasePlayer* Player, BoneList bone)
	{
		 
		auto active = local_player->get_active_weapon();
		const int ammo = active->LoadedAmmo();
	 

		Vector BonePos = Player->get_bone_transform(48)->get_bone_position();
		const float Dist = Distance3D(LP_Pos, BonePos);
		if (Dist > 0.001f  ) {
			float speed = GetBulletSpeed();
			if (speed == NULL)
				speed = 250.f;

			const float BulletTime = Dist / speed;
			const Vector vel = Player->GetVelocity();
			const Vector PredictVel = vel * BulletTime * 0.75f;
			BonePos += PredictVel;
			const float gravity = GetGravity(ammo);
			BonePos.y += (4.905f * BulletTime * BulletTime) * gravity;
		}
	 
		return BonePos;
	}
	inline void Normalize(float& Yaw, float& Pitch)
	{
		if (Pitch < -89)
			Pitch = -89;
		else if (Pitch > 89)
			Pitch = 89;
		if (Yaw < -360)
			Yaw += 360;
		else if (Yaw > 360)
			Yaw -= 360;
	}
	inline double ToRad(double degree)
	{
		double pi = 3.14159265359;
		return (degree * (pi / 180));
	}
	inline vector4 ToQuat(Vector Euler) {

		double heading = ToRad(Euler.x);
		double attitude = ToRad(Euler.y);
		double bank = ToRad(Euler.z);

		double c1 = m_cos(heading / 2);
		double s1 = m_sin(heading / 2);
		double c2 = m_cos(attitude / 2);
		double s2 = m_sin(attitude / 2);
		double c3 = m_cos(bank / 2);
		double s3 = m_sin(bank / 2);
		double c1c2 = c1 * c2;
		double s1s2 = s1 * s2;
		vector4 Quat;
		Quat.w = c1c2 * c3 - s1s2 * s3;
		Quat.x = c1c2 * s3 + s1s2 * c3;
		Quat.y = s1 * c2 * c3 + c1 * s2 * s3;
		Quat.z = c1 * s2 * c3 - s1 * c2 * s3;
		vector4 Quat2;
		Quat2 = { Quat.y, Quat.z, (Quat.x * -1), Quat.w };
		return Quat2;
	}
	inline void Psilent(BasePlayer* player)
	{

		const auto Local = local_player->get_bone_transform(head)->get_bone_position();
		UINT64 PlayerEyes = mem::read<UINT64>((uintptr_t)local_player + O::BasePlayer::eyes);

		Vector PlayerPos;
		if (vars::Prediction)
		{
			if (vars::misc::eyeoffset && unity::GetKey(rust::classes::KeyCode::Y))
			{
				PlayerPos = Prediction(Local, player, neck) - Vector(0, 1.3, 0);//Vector(0, 1.3f, 0) 
			}
			 
			else
				PlayerPos = Prediction(Local, player, neck);//
		}
		else
		{
			if (vars::misc::eyeoffset && unity::GetKey(rust::classes::KeyCode::Y))
			{
				PlayerPos = player->get_bone_transform(50)->get_bone_position() - Vector(0, 1.3, 0);
			}
			 
			else PlayerPos = player->get_bone_transform(50)->get_bone_position();
		}
		auto Offset = CalcAngle(Local, PlayerPos) - local_player->GetVA();
		Normalize(Offset.y, Offset.x);
		const auto RecoilToAngles = local_player->GetRA();
		auto AngleToAim = local_player->GetVA() + Offset;
		if (vars::RecoilControlSystem)
		{
			AngleToAim = AngleToAim - RecoilToAngles;
		}
		vector4 QuatAngles = ToQuat({ AngleToAim.x, AngleToAim.y, 0.0f });
		Normalize(AngleToAim.y, AngleToAim.x);

		mem::write<vector4>(PlayerEyes + 0x44, QuatAngles);
	}
	inline void Target(BasePlayer* player)
	{
		const auto Local = local_player->get_bone_transform(46)->get_bone_position();
		Vector PlayerPos;
		if (vars::Prediction)
		{
			if (vars::misc::eyeoffset && unity::GetKey(rust::classes::KeyCode::Y))
			{
				PlayerPos = Prediction(Local, player, neck) - Vector(0, 1.3, 0);//Vector(0, 1.3f, 0) 
			}

			else
				PlayerPos = Prediction(Local, player, neck);//
		}
		else
		{
			if (vars::misc::eyeoffset && unity::GetKey(rust::classes::KeyCode::Y))
			{
				PlayerPos = player->get_bone_transform(50)->get_bone_position() - Vector(0, 1.3, 0);
			}

			else PlayerPos = player->get_bone_transform(50)->get_bone_position();
		}
		auto Offset = CalcAngle(Local, PlayerPos) - local_player->GetVA();
		Normalize(Offset.y, Offset.x);
		const auto RecoilToAngles = local_player->GetRA();
		auto AngleToAim = local_player->GetVA() + Offset;
		if (vars::RecoilControlSystem)
		{
			AngleToAim = AngleToAim - RecoilToAngles;
		}
		
		Normalize(AngleToAim.y, AngleToAim.x);
		local_player->SetVA(AngleToAim);
	}


	void miscvis(DWORD64 ObjectClass, char* buff, bool boolean, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, Color Col);

	void stash(DWORD64 ObjectClass, DWORD64 Object, char* buff);

	void dropped_items(vector2 w2s_position, wchar_t* label, Color color, wchar_t* name = _(L""));
	void draw_item(vector2 w2s_position, uintptr_t label, Color color);

	void draw_player(BasePlayer* player);

	void RadarPlayer(BasePlayer* player);
	void HandChams(BasePlayer* player);



	}
	
	void ESPLoop() {
		float FOV = 1000000.f;
		BasePlayer* AimEntity = 0;
		bool LP_isValid = false;
		uintptr_t ClientEntities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
		uintptr_t ClientEntities_list = mem::read<uintptr_t>(ClientEntities + 0x10);
		uintptr_t ClientEntities_values = mem::read<uintptr_t>(ClientEntities_list + 0x28);
		int EntityCount = mem::read<int>(ClientEntities_values + 0x10);
		if (!EntityCount) return;
		uintptr_t EntityBuffer = mem::read<uintptr_t>(ClientEntities_values + 0x18);
		weapon* weapon_1 = local_player->get_active_weapon();
		uintptr_t active = mem::read<uintptr_t>((uintptr_t)weapon_1 + O::Item::heldEntity);
		char* classname = weapon_1->ClassName();
		bool weaponmelee = weapon_1 && classname && (m_strstr(classname, _("BaseMelee")) || m_strstr(classname, _("Jackhammer")));
		auto get_client_entities = [&]() {
			esp::client_entities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
		};
		if (!esp::client_entities)
			get_client_entities();

		rust::classes::list* entity_list = (rust::classes::list*)esp::client_entities;

		auto list_value = entity_list->get_value<uintptr_t>();
		if (!list_value) {
			get_client_entities();
			return;
		}

		auto size = entity_list->get_size();
		if (!size) {
			get_client_entities();
			return;
		}

		auto buffer = entity_list->get_buffer<uintptr_t>();
		if (!buffer) {
			get_client_entities();
			return;
		}
		for (int i = 0; i < EntityCount; i++) {
			auto current_object = *reinterpret_cast<uintptr_t*>(buffer + 0x20 + (i * 0x8));
			if (!current_object || current_object <= 100000)
				continue;

			auto base_object = *reinterpret_cast<uintptr_t*>(current_object + 0x10);
			if (!base_object || base_object <= 100000)
				continue;

			auto object = *reinterpret_cast<uintptr_t*>(base_object + 0x30);
			if (!object || object <= 100000)
				continue;
			
			auto ent_ = *reinterpret_cast<uintptr_t*>(base_object + 0x28);
			if (!ent_)
				continue;

			auto ent_class = *reinterpret_cast<uintptr_t*>(ent_);
			if (!ent_class)
				continue;

			auto entity_class_name = (char*)*reinterpret_cast<uintptr_t*>(ent_class + 0x10);
			if (!entity_class_name)
				continue;

			wchar_t* esp_name;
			Color esp_color(1, 0, 1, 1);

			auto game_object = *reinterpret_cast<uintptr_t*>(object + 0x30);
			if (!game_object)
				continue;

			auto transform = *reinterpret_cast<uintptr_t*>(game_object + 0x8);
			if (!transform)
				continue;

			auto visual_state = *reinterpret_cast<uintptr_t*>(transform + 0x38);
			if (!visual_state)
				continue;

			auto world_position = *reinterpret_cast<Vector*>(visual_state + 0x90);
			if (world_position.is_empty())
				continue;

			uintptr_t object_name_ptr = mem::read<uintptr_t>(object + 0x60);
			if (!object_name_ptr)
				continue;

			auto object_name = *reinterpret_cast<esp::rust_str*>(object_name_ptr);
			if (!object_name.zpad)
				continue;

			uintptr_t Entity = mem::read<uintptr_t>(EntityBuffer + 0x20 + (i * 0x8)); /*if (Entity <= 100000) continue;*/
			uintptr_t Object = mem::read<uintptr_t>(Entity + 0x10); /*if (Object <= 100000) continue;*/
			uintptr_t ObjectClass = mem::read<uintptr_t>(Object + 0x30);// if (ObjectClass <= 100000) continue;
			pUncStr name = mem::read<pUncStr>(ObjectClass + 0x60); //if (!name) continue;
			char* buff = name->stub;
			WORD tag = *reinterpret_cast<WORD*>(ObjectClass + 0x54);
			DWORD64 ent = safe_read(Object + 0x28, UINT64);


			float last_recycler = 0.f;
			if (vars::misc::norecycler && *(int*)(entity_class_name) == 'yceR' && get_fixedTime() > last_recycler + 0.35f) {
				if (local_player->get_bone_transform(48)->get_bone_position().distance(world_position) < 4.5f)
					unity::ServerRPC(ent, _(L"SVSwitch"));
				last_recycler = get_fixedTime();
			}
			
			if (*(int*)(entity_class_name) == 'porD') {
				if (!vars::visuals::dropped_items)
					continue;

				if (*(int*)(entity_class_name + 40) == 'kcab')
					continue;

				if (*(int*)(object_name.zpad) == 'orra')
					continue;

				if (*(int*)(object_name.zpad + 12) == 'ian.')
					continue;

				auto Item = *reinterpret_cast<uintptr_t*>(ent + 0x170); // public Item item; || public class WorldItem : BaseEntity
				if (!Item)
					continue;

				auto item = reinterpret_cast<weapon*>(Item);

				auto item_name = item->get_weapon_name();

				esp_color = Color(196, 124, 0, 255);

				vector2 w2s_position = {};
				if (esp::out_w2s(world_position, w2s_position))
					esp::dropped_items(w2s_position, 0, esp_color, item_name);

				continue;
			}

			auto player = reinterpret_cast<BasePlayer*>(ent);




			if (m_strstr(buff, _("Local"))) {
				BasePlayer* Player = *reinterpret_cast<BasePlayer**>(Object + 0x28);
				if (!*reinterpret_cast<uintptr_t*>(Player + net) || *reinterpret_cast<bool*>(Player + 0x18) || !*reinterpret_cast<uintptr_t*>(Player + playerModel)) continue;
				if (Player != local_player) {}
				Vector pos = Player->Position();
				local_player = Player;
				LP_isValid = true;

				if (local_player->is_local_player())
				{
					local_player = reinterpret_cast<BasePlayer*>(ent);
					esp::HandChams(player);
				}
			}

			else if (m_strstr(buff, _("player.prefab")))
			{
				BasePlayer* Player = mem::read<BasePlayer*>(Object + 0x28);
				aim_target best_target = aim_target();
				if (!*reinterpret_cast<uintptr_t*>(Player + net)  || *reinterpret_cast<bool*>(Player + 0x18)  || !*reinterpret_cast<uintptr_t*>(Player + playerModel)) continue;
				if (!Player->IsValid()) continue;
				if (Player->IsDead()) continue;
			 	if (Player->is_teammate(local_player)) continue;
				esp::matrix = unity::get_view_matrix();
				if (Player->is_sleeping() && !vars::visuals::sleeper_esp) continue;
				if (Player->IsNpc() && !vars::visuals::sleeper_esp)continue;
				//if(Player->)
				//if (get_IsNpc(Player->get_player_model())) { if (!vars::visuals::npc_esp) continue; }
				if (vars::weapon::silent_melee && weaponmelee) {
					AimResult target = TargetMeleeTest((BasePlayer*)ent, active);
					DoMeleeAttack(target, active, true);
				}
				const float Distance = Distance3D(local_player->get_bone_transform(48)->get_bone_position(), Player->get_bone_transform(48)->get_bone_position());
				if (Distance <= vars::PlayerEspDistance)
				{
					
					esp::draw_player(Player);
					esp::RadarPlayer(Player);

				}

				float CurFOV = 9999999.f;
				if (vars::visuals::chams) {

					auto _multiMesh = mem::read<uintptr_t>(player->get_player_model() + O::PlayerModel::_multiMesh); //SkinnedMultiMesh _multiMesh;
					if (_multiMesh) {
						auto render = get_Renderers(_multiMesh);

						for (int i = 0; i < render->get_size(); i++) {
							auto renderer = render->get_value(i);

							if (renderer) {
								auto material = get_material(renderer);
								if (material) {
									uintptr_t shader = unity::LoadAsset(unity::bundle, _(L"chamslit"), unity::GetType(_("UnityEngine"), _("Shader")));
									
									unity::set_shader(material, shader);
									
									SetColor(material, (L"_ColorVisible"), col(0.0, 0.5, 0.5, 1.f));
									SetColor(material, (L"_ColorBehind"), col(0.5, 0.0, 0.5, 1.f));
								}
							}
						}
					}

				}
				if (LP_isValid)
				{
					if (player->is_local_player())
					{
						local_player = reinterpret_cast<BasePlayer*>(ent);
					}
					else {
						if (local_player) {
							auto target = aim_target();
							target.pos = player->get_bone_transform(19)->get_bone_position();
							auto distance = local_player->get_bone_transform(48)->get_bone_position().get_3d_dist(target.pos);
							target.distance = distance;
							auto fov = unity::get_fov(target.pos);
							target.fov = fov;
							target.player = player;
							if (target < best_target)
								best_target = target;
						}

					}

				}
				else local_player = nullptr;
			}

			//--NEW-TECHNOLOGIES-BY-MrYasin------------------------------------------------------------------------------------------------------------------------------------//
			if (vars::visuals::stash || vars::visuals::hackable_crate_esp) {
				esp::stash(ObjectClass, Entity, buff);

			}
			//----------------------------------------------------------------------------RESOURCE----------------------------------------------------------------------------//
			if (vars::visuals::stone_ore || vars::visuals::sulfur_ore || vars::visuals::metal_ore || vars::visuals::cloth) {
				esp::miscvis(ObjectClass, buff, vars::visuals::stone_ore, vars::visuals::showDistance_resource, vars::visuals::distance_resource, _("stone-ore.prefab"), _(L"Stone Ore"), Color(128, 128, 128, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::sulfur_ore, vars::visuals::showDistance_resource, vars::visuals::distance_resource, _("sulfur-ore.prefab"), _(L"Sulfur ore"), Color(255, 215, 0, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::metal_ore, vars::visuals::showDistance_resource, vars::visuals::distance_resource, _("metal-ore.prefab"), _(L"Metal ore"), Color(139, 69, 19, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::cloth, vars::visuals::showDistance_resource, vars::visuals::distance_resource, _("hemp-collectable.prefab"), _(L"Hemp"), Color(50, 205, 50, 255));
			}
			//----------------------------------------------------------------------------VEHICLE-----------------------------------------------------------------------------//
			if (vars::visuals::minicopter || vars::visuals::scrap_heli || vars::visuals::boat || vars::visuals::rhib || vars::visuals::heli_esp) {
				esp::miscvis(ObjectClass, buff, vars::visuals::heli_esp, vars::visuals::showDistance_vehicle, vars::visuals::distance_vehicle, _("assets/prefabs/npc/patrol helicopter/patrolhelicopter.prefab"), _(L"Patrol Helicopter"), Color(56, 76, 255, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::minicopter, vars::visuals::showDistance_vehicle, vars::visuals::distance_vehicle, _("minicopter.entity.prefab"), _(L"Minicopter"), Color(0, 0, 255, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::scrap_heli, vars::visuals::showDistance_vehicle, vars::visuals::distance_vehicle, _("scraptransporthelicopter.prefab"), _(L"Scrap Heli"), Color(0, 0, 139, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::boat, vars::visuals::showDistance_vehicle, vars::visuals::distance_vehicle, _("rowboat.prefab"), _(L"Boat"), Color(173, 216, 230, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::rhib, vars::visuals::showDistance_vehicle, vars::visuals::distance_vehicle, _("rhib.prefab"), _(L"RHIB"), Color(224, 255, 255, 255));
			}
			//-----------------------------------------------------------------------------TURRET-----------------------------------------------------------------------------//
			if (vars::visuals::autoturret || vars::visuals::trap || vars::visuals::mine || vars::visuals::flame_turret || vars::visuals::sam_site || vars::visuals::bear_trap) {
				esp::miscvis(ObjectClass, buff, vars::visuals::autoturret, vars::visuals::showDistance_turret, vars::visuals::distance_turret, _("autoturret_deployed.prefab"), _(L"Auto Turret"), Color(255, 165, 0, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::trap, vars::visuals::showDistance_turret, vars::visuals::distance_turret, _("guntrap.deployed.prefab"), _(L"Shotgun Trap"), Color(105, 105, 105, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::mine, vars::visuals::showDistance_turret, vars::visuals::distance_turret, _("landmine.prefab"), _(L"Landmine"), Color(138, 43, 226, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::flame_turret, vars::visuals::showDistance_turret, vars::visuals::distance_turret, _("flameturret.deployed.prefab"), _(L"Flame Turret"), Color(255, 140, 0, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::sam_site, vars::visuals::showDistance_turret, vars::visuals::distance_turret, _("sam_site_turret_deployed.prefab"), _(L"SAM Site"), Color(176, 224, 230, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::bear_trap, vars::visuals::showDistance_turret, vars::visuals::distance_turret, _("beartrap.prefab"), _(L"Beartrap"), Color(255, 248, 220, 255));
			}
			//------------------------------------------------------------------------------CRATE-----------------------------------------------------------------------------//
			if (vars::visuals::airdrops || vars::visuals::eliitecrate || vars::visuals::militarcrate || vars::visuals::helicrate || vars::visuals::bradleycrate) {
				esp::miscvis(ObjectClass, buff, vars::visuals::airdrops, vars::visuals::showDistance_crate, vars::visuals::distance_crate, _("supply_drop.prefab"), _(L"Airdrop"), Color(0, 139, 139, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::eliitecrate, vars::visuals::showDistance_crate, vars::visuals::distance_crate, _("crate_elite.prefab"), _(L"Elite Crate"), Color(0, 139, 139, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::militarcrate, vars::visuals::showDistance_crate, vars::visuals::distance_crate, _("crate_normal.prefab"), _(L"Military Crate"), Color(1, 68, 33, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::helicrate, vars::visuals::showDistance_crate, vars::visuals::distance_crate, _("heli_crate.prefab"), _(L"Heli Crate"), Color(1, 50, 32, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::bradleycrate, vars::visuals::showDistance_crate, vars::visuals::distance_crate, _("bradley_crate.prefab"), _(L"Bradley Crate"), Color(173, 255, 47, 255));
			}
			//-----------------------------------------------------------------------------PLAYERS----------------------------------------------------------------------------//
			if (vars::visuals::corpses || vars::visuals::Backpack) {
				esp::miscvis(ObjectClass, buff, vars::visuals::corpses, vars::visuals::showDistance, vars::visuals::distance_player, _("player_corpse.prefab"), _(L"Player Corpse"), Color(255, 0, 0, 255));
				esp::miscvis(ObjectClass, buff, vars::visuals::Backpack, vars::visuals::showDistance, vars::visuals::distance_player, _("item_drop_backpack.prefab"), _(L"Player Backpack"), Color(139, 0, 139, 255));
			}
		}
		return;
}
	
