#pragma once
#include "memory/il2cpp.hpp"
#include "vars.hpp"
#include "offsets.h"
#include <math.h>
#include "Keybind.h"
//#include "string_format.h"
#pragma once
#include <array>
#include "utils/vector.hpp"

struct shot_record_t
{
	float m_time;
	Vector m_start, m_end;
	int m_damage;

};
int shoot_i = 0;
shot_record_t shoot_arr[100]{};
Vector m_debugcam_toggle_pos;
Vector m_debugcam_pos;

bool just_shot = false;
bool did_reload = false;
float time_since_last_shot = 0.0f;
float fixed_time_last_shot = 0.0f;
float desyncTimeRaw = 0.f;
float desyncTimeClamped = 0.f;
float tickDeltaTime = 0.f;
//TickInterpolator ticks;
bool isInAir = false;
bool magic_projectile_test = false;
bool manual = false;
bool autoshot = false;
bool manipulate_vis = false;
Vector cLastTickPos{};
Vector best_lean{};
float insta_travel_check_time = -1.f;
bool can_manipulate(BasePlayer* ply,  float mm_eye = 6.f) //7m only check rn
{
	Vector v = *reinterpret_cast<Vector*>((uintptr_t)ply + eyes);
	Vector re_p = ply->get_bone_transform(neck)->get_bone_position() + ply->get_bone_transform(neck)->get_bone_position_up() * (ply->get_player_eyes()->get_view_offset().y + v.y);

	auto camera_pos = unity::get_camera_pos();
	aim_target target = local_player->get_aimbot_target(camera_pos);

	Vector pos = target.player->get_bone_transform(48)->get_bone_position();
	 

	auto do_check = [&](Vector a) {
		Vector p = re_p + a;
		if (!vars::stor::closestPlayer)
			return false;
		if (!ply->is_visible(p, re_p))
			return false;
		Vector choise = Vector(0, 0, 0);
		if (vars::visuals::angles) {
			Sphere(p, 0.02f, col(0.1, 0.3, 0.9, 0), 0.01f, 10);
		}

		auto tick_time = local_player->get_last_sent_ticket_time();
		float desyncTime = (unity::get_realtimesincestartup() - tick_time) - 0.03125 * 3;
		float mm_max_eye = (0.1f + ((desyncTime + 2.f / 60.f + 0.125f) * 1.5f) * local_player->MaxVelocity()) - 0.05f;
		float max_v_multicplier = 4.5f;
		float v_mm_max_eye = mm_max_eye / max_v_multicplier;

		if (!ply->is_visible(p, pos)) {
			bool t = false;
			 

			Vector z = pos;
			std::array<Vector, 1> arr = {

			};

			for (auto v : arr) {
				if (ply->is_visible(p, v)) {
					if (ply->is_visible(z, v)) {
						t = true;
						break;
					}
				}
			}

			if (!t) return false;
		}

		best_lean = a;
		return true;
	};

	for (float y = 1.5f; y > -1.5f; y -= vars::weapon::thick_bullet ? 0.3f : 0.1f) {
		int points = vars::weapon::thick_bullet ? 7 : 20;
		float step = (M_PI_2) / points;
		float x, z, current = 0;
		for (size_t i = 0; i < points; i++)
		{
			x = m_sin(current) * mm_eye;
			z = m_cos(current) * mm_eye;

			Vector p1 = Vector(x, y, z);
			Vector p2 = Vector(-x, y, z);
			Vector p3 = Vector(x, y, -z);
			Vector p4 = Vector(-x, y, -z);

			if (do_check(p1)) return true;
			if (do_check(p2)) return true;
			if (do_check(p3)) return true;
			if (do_check(p4)) return true;

			current += step;
		}
	}

	best_lean = Vector(0, 0, 0);
	return false;
}


 
bool LineCircleIntersection(Vector center,
	float radius,
	Vector rayStart,
	Vector rayEnd,
	float& offset)
{
	vector2 P(rayStart.x, rayStart.z);
	vector2 Q(rayEnd.x, rayEnd.z);

	float a = Q.y - P.y;
	float b = P.x - Q.x;
	float c = (a * (P.x) + b * (P.y)) * -1.f;

	float x = center.x;
	float y = center.z;

	float c_x = (b * ((b * x) - (a * y)) - a * c) / (my_pow(a, 2) + my_pow(b, 2));
	float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (my_pow(a, 2) + my_pow(b, 2));

	vector2 closestPoint(c_x, c_y);

	float distance = P.Distance(Q);

	if (P.Distance(closestPoint) > distance || Q.Distance(closestPoint) > distance)
	{
		return false;
	}

	if (radius > closestPoint.Distance(vector2(center.x, center.z)))
	{
		vector2 P(rayStart.x, rayStart.y);
		vector2 Q(rayEnd.x, rayEnd.y);

		float a = Q.y - P.y;
		float b = P.x - Q.x;
		float c = (a * (P.x) + b * (P.y)) * -1.f;

		float x = center.x;
		float y = center.y;

		float c_x = (b * ((b * x) - (a * y)) - a * c) / (my_pow(a, 2) + my_pow(b, 2));
		float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (my_pow(a, 2) + my_pow(b, 2));

		vector2 closestPoint(c_x, c_y);
		if (radius > closestPoint.Distance(vector2(center.x, center.y)))
		{
			return true;
		}
		else
		{
			offset += m_abs(center.y - closestPoint.y);
			return false;
		}
	}

	return false;
};
#pragma optimize("", off)
#pragma code_seg(".text")
inline int64_t get_rbx_value()
{
	static __declspec(allocate(".text")) char fn_stub[] = {
		0x48,
		0x89,
		0xD8, // mov    rax,rbx
		0xc3 // ret
	};

	return ((int64_t(*)())(&fn_stub))();
}
namespace hooks {
	namespace orig {
		static auto OnAttacked = reinterpret_cast<void (*)(void*, HitTest*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnAttacked"), 1, _(""), _(""))));
		static auto Original_OnCameraPositionChanged = reinterpret_cast<void (*)(uintptr_t , uintptr_t,BasePlayer )>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("OnCameraPositionChanged"), 1, _(""), _(""))));

		static auto baseplayer_client_input = reinterpret_cast<void (*)(BasePlayer*, input_state*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), -1, _(""), _(""))));
		static auto BaseProjectile_OnSignal = reinterpret_cast<void (*)(BaseProjectile*, int, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("OnSignal"), 2, _(""), _(""))));
		static auto playerwalkmovement_client_input = reinterpret_cast<void (*)(playerwalkmovement*, uintptr_t, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		static auto VisUpdateUsingCulling = reinterpret_cast<void (*)(ViewModel*, pUncStr, int)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ViewModel"), _("Play"), 1, _(""), _(""))));
		static auto DoFixedUpdate = reinterpret_cast<void (*)(playerwalkmovement*, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		static auto blocksprint = reinterpret_cast<void (*)(BasePlayer*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("BlockSprint"), 1, _(""), _(""))));
		static auto OnNetworkMessage = reinterpret_cast<void (*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("OnNetworkMessage"), 1, _(""), _(""))));
		static auto CheckCapsule = reinterpret_cast<bool(*)(Vector, Vector, float, int, rust::classes::QueryTriggerInteraction)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 0, _(""), _("UnityEngine"))));
		static auto Run = reinterpret_cast<rust::classes::string(*)(uintptr_t, uintptr_t, rust::classes::string, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ConsoleSystem"), _("Run"), 3, _(""), _(""))));
		static auto baseprojectile_launchprojectile = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));
		//	static auto initDoHit = reinterpret_cast<bool (*)(Projectile*, HitTest*, Vector, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), -1, _(""), _(""))));
		uintptr_t playerprojectileattack;
		uintptr_t serverrpc_projectileshoot;
		uintptr_t serverrpc_processattack;
	}

	//static auto serverrpc_projecileshoot = rb::pattern::find_rel(//
	//	_("GameAssembly.dll"), _("4C 8B 0D ? ? ? ? 48 8B 75 30"));

	static auto set_sprinting = reinterpret_cast<void (*)(modelstate*, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));

	static auto draw_get = reinterpret_cast<void (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Get"), 0, _(""), _("UnityEngine"))));

	static auto set_flying = reinterpret_cast<void (*)(modelstate * model_state, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_flying"), 1, _(""), _(""))));

	static auto GetSpeed = reinterpret_cast<float (*)(BasePlayer * baseplayer, float running, float ducking)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 2, _(""), _(""))));

	static auto get_ducked = reinterpret_cast<bool (*)(modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("get_ducked"), 0, _(""), _(""))));

	static auto IsSwimming = reinterpret_cast<bool (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));

	static auto ServerRPC = reinterpret_cast<void (*)(uintptr_t, rust::classes::string funcName)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));

	static auto OnLand = reinterpret_cast<void (*)(BasePlayer*, float fVelocity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));

	//static auto DoHit = reinterpret_cast<bool (*)(Projectile*, HitTest*, Vector, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), -1, _(""), _(""))));

	static auto Update = reinterpret_cast<void (*)(void* instance)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PerformanceUI"), _("Update"), 0, _(""), _("Facepunch"))));

	static auto CheckCapsule = reinterpret_cast<bool(*)(Vector, Vector, float, int, rust::classes::QueryTriggerInteraction)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 0, _(""), _("UnityEngine"))));

	//static auto ServerRPC_int = reinterpret_cast<void (*)(BaseProjectile*, rust::classes::string funcName, unsigned int arg1, uintptr_t)>(mem::game_assembly_base + CO::BaseEntity$$ServerRPC_uint_);

	//static auto change_code_rpc = reinterpret_cast<void (*)(BasePlayer*, rust::classes::string, uintptr_t, bool, uintptr_t)>(mem::game_assembly_base + CO::BaseEntity$$ServerRPC_string_bool_Address); //BaseEntity$$ServerRPC<string, bool> Address

	void init_hooks() {

		orig::Original_OnCameraPositionChanged = reinterpret_cast<void (*)(uintptr_t, uintptr_t, BasePlayer)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("OnCameraPositionChanged"), 1, _(""), _(""))));


		orig::OnNetworkMessage = reinterpret_cast<void (*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("OnNetworkMessage"), 1, _(""), _(""))));
		orig::BaseProjectile_OnSignal = reinterpret_cast<void (*)(BaseProjectile*, int, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("OnSignal"), 2, _(""), _(""))));
		orig::baseplayer_client_input = reinterpret_cast<void (*)(BasePlayer*, input_state*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), -1, _(""), _(""))));
		orig::playerwalkmovement_client_input = reinterpret_cast<void (*)(playerwalkmovement*, uintptr_t, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		orig::VisUpdateUsingCulling = reinterpret_cast<void (*)(ViewModel*, pUncStr, int)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ViewModel"), _("Play"), 1, _(""), _(""))));

		orig::DoFixedUpdate = reinterpret_cast<void (*)(playerwalkmovement*, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		orig::blocksprint = reinterpret_cast<void (*)(BasePlayer*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("BlockSprint"), 1, _(""), _(""))));
		/*serverrpc_projecileshoot = rb::pattern::find_rel(
			_("GameAssembly.dll"), _("4C 8B 0D ? ? ? ? 48 8B 75 30"));*/
		orig::OnAttacked = reinterpret_cast<void (*)(void*, HitTest*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnAttacked"), 1, _(""), _(""))));


		Update = reinterpret_cast<void (*)(void* instance)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PerformanceUI"), _("Update"), 0, _(""), _("Facepunch"))));

		//change_code_rpc = reinterpret_cast<void (*)(BasePlayer*, rust::classes::string, uintptr_t, bool, uintptr_t)>(mem::game_assembly_base + CO::BaseEntity$$ServerRPC_string_bool_Address);

		set_sprinting = reinterpret_cast<void (*)(modelstate*, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));

		draw_get = reinterpret_cast<void (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Get"), 0, _(""), _("UnityEngine"))));

		set_flying = reinterpret_cast<void (*)(modelstate * model_state, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_flying"), 1, _(""), _(""))));

		GetSpeed = reinterpret_cast<float (*)(BasePlayer * baseplayer, float running, float ducking)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 2, _(""), _(""))));

		get_ducked = reinterpret_cast<bool (*)(modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("get_ducked"), 0, _(""), _(""))));

		IsSwimming = reinterpret_cast<bool (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));

		ServerRPC = ServerRPC = reinterpret_cast<void (*)(uintptr_t, rust::classes::string funcName)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));

		OnLand = reinterpret_cast<void (*)(BasePlayer*, float fVelocity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));

		//	DoHit = reinterpret_cast<bool (*)(Projectile*, HitTest*, Vector, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), -1, _(""), _(""))));

		CheckCapsule = reinterpret_cast<bool(*)(Vector, Vector, float, int, rust::classes::QueryTriggerInteraction)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 0, _(""), _("UnityEngine"))));

		//	ServerRPC_int = reinterpret_cast<void (*)(BaseProjectile*, rust::classes::string funcName, unsigned int arg1, uintptr_t)>(mem::game_assembly_base + CO::BaseEntity$$ServerRPC_uint_);

		orig::baseprojectile_launchprojectile = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));

		//orig::initDoHit = reinterpret_cast<bool (*)(Projectile*, HitTest*, Vector, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), -1, _(""), _(""))));
	}

	 

	static bool wakeup{ true };
	uintptr_t game_object;
	void hk_performance_ui_update(void* instance) {
		if (wakeup)
		{
			game_object = il2cpp::methods::object_new(il2cpp::init_class(_("GameObject"), _("UnityEngine")));
			gui::methods::create(game_object, _(L""));
			gui::methods::add_component(game_object, il2cpp::type_object(_(""), _("DevControls")));
			gui::methods::dont_destroy_on_load(game_object);
			wakeup = false;
		}
		Update(instance);
	}

	double CalcBulletDrop(double height, double DepthPlayerTarget, float velocity, float gravity) {
		auto camera_pos = unity::get_camera_pos();

		aim_target target = local_player->get_aimbot_target(camera_pos);
	
	//	auto camera_pos = unity::get_camera_pos();
		auto transform = target.player->get_bone_transform(48);
		auto position = transform->get_bone_position();
		auto distance = local_player->get_bone_transform(48)->get_bone_position().Distance(position);

		double pitch = (m_atan2(height, DepthPlayerTarget));
		double BulletVelocityXY = velocity * m_cos(pitch);
		double Time = DepthPlayerTarget / BulletVelocityXY;
		auto item = local_player->get_active_weapon();
		const auto item_id = item->get_item_definition_id();
		if (item_id == 1545779598) //ak 47
		{
			double TotalVerticalDrop = 1.000000 * 0.600000;

			if (distance > 400.f) {
				double TotalVerticalDrop = (0.751 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 350.f) {
				double TotalVerticalDrop = (0.745 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 340.f) {
				double TotalVerticalDrop = (0.7355 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 330.f) {
				double TotalVerticalDrop = (0.731 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 300.f) {
				double TotalVerticalDrop = (0.716 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 250.f) {
				double TotalVerticalDrop = (0.622 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 200.f) {
				double TotalVerticalDrop = (0.5941 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 150.f) {
				double TotalVerticalDrop = (0.5727 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance > 100.f) {
				double TotalVerticalDrop = (0.567 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}
			if (distance < 100.f) {
				double TotalVerticalDrop = (0.569 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}

		}

		else if (item_id == 1318558775) //MP5A4
		{
			double TotalVerticalDrop = 1.000000 * 0.700000;

		}
		else if (item_id == -1812555177) //LR-300
		{
			double TotalVerticalDrop = 1.000000 * 0.600000;

		}
		else if (item_id == -904863145) //Полуавтоматическая винтовка
		{
			double TotalVerticalDrop = 1.000000 * 0.600000;

		}
		else if (item_id == 1796682209) //Самодельный пистолет-пулемет
		{
			double TotalVerticalDrop = 1.000000 * 0.700000;
		}
		else if (item_id == 1373971859) //Револьвер Питон
		{
			double TotalVerticalDrop = 1.000000 * 0.700000;

		}
		else if (item_id == 818877484) //Полуавтоматический пистолет
		{
			double TotalVerticalDrop = 1.000000 * 0.700000;

		}
		else if (item_id == -1123473824) //Многозарядный гранатомет
		{
			if (distance < 100.f) {
				double TotalVerticalDrop = (0.58 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}

		}
		else if (item_id == 28201841) //Винтовка M39
		{
			double TotalVerticalDrop = 1.000000 * 0.600000;
		}
		else if (item_id == 884424049) //Блочный лук
		{
			double TotalVerticalDrop = 0.750000 * 0.004500;
		}
		else if (item_id == 649912614) //Револьвер
		{
			double TotalVerticalDrop = 1.000000 * 0.700000;

		}
		else if (item_id == -765183617) //Двуствольный дробовик
		{
			double TotalVerticalDrop = 1.000000 * 1.000000;
		}
		else if (item_id == -75944661) //eoka
		{
			double TotalVerticalDrop = -2;

		}
		else if (item_id == 1953903201) //Гвоздомет
		{
			if (distance < 55.f) {
				double TotalVerticalDrop = (0.5465 * gravity * Time * Time);
				//return TotalVerticalDrop * 10;
			}
			else if (distance > 56.f) {
				double TotalVerticalDrop = (0.5465 * gravity * Time * Time);
				//return TotalVerticalDrop * 10;
			}
			else if (distance > 78.f) {
				double TotalVerticalDrop = (0.56 * gravity * Time * Time);
				//return TotalVerticalDrop * 10;
			}

		}
		else if (item_id == -778367295) //Винтовка L96
		{
			double TotalVerticalDrop = 1.000000 * 0.600000;

		}
		else if (item_id == 1965232394) //Арбалет
		{

			double TotalVerticalDrop = 0.750000 * 0.005000;

		}
		else if (item_id == 1588298435) //Винтовка = болт
		{
			double TotalVerticalDrop = 1.000000 * 0.600000;

		}

		else if (item_id == -852563019) //М92 Беретта
		{

			double TotalVerticalDrop = 1.000000 * 0.700000;

		}
		else if (item_id == 1103488722) //Снежкомет
		{
			if (distance < 100.f) {
				double TotalVerticalDrop = (0.58 * gravity * Time * Time);
				return TotalVerticalDrop * 10;
			}

		}

		else if (item_id == -1758372725) //Пистолет-пулемет Томпсона
		{
			double TotalVerticalDrop = 1.000000 * 0.700000;

		}
		else if (item_id == -2069578888) //Пулемет М249
		{
			double TotalVerticalDrop = 1.000000 * 0.600000;
		}

		if (distance < 50.f)
		{
			double TotalVerticalDrop = (0.451f * gravity * Time * Time);
			return TotalVerticalDrop * 10;
		}

		if (distance < 100.f)
		{
			double TotalVerticalDrop = (0.460f * gravity * Time * Time);
			return TotalVerticalDrop * 10;
		}
		if (distance >= 100.f)
		{
			double TotalVerticalDrop = (0.510f * gravity * Time * Time);
			return TotalVerticalDrop * 10;
		}


		if (distance >= 150.f)
		{
			double TotalVerticalDrop = (0.620f * gravity * Time);
			return TotalVerticalDrop * 10;
		}

		if (distance >= 200.f)
		{
			double TotalVerticalDrop = (0.672f * gravity * Time);
			return TotalVerticalDrop * 10;
		}




	}

	float GetGravityBullet(int ammoid) {
		switch (ammoid) {
		case -1211166256: // default 5.56
			return 1.22f;
		case -1712070256: // скоростные 5.56
			return 1.12f; // 1.12
		case 605467368: // зажигательные 5.56
			return 1.45f;
		case -1321651331: // разрывные 5.56
			return 1.41f;
		case 785728077: // обычные пистолетные
			return 1.28f;
		case -1691396643: // скоростные пистолетные
			return 1.28f;
		case 51984655: // зажигательные пистолетные
			return 1.28f;
		case -1234735557: // обычные стрелы
			return 0.72f;
		case -1023065463: // скоростные стрелы
			return 0.47f;
		case 14241751: // огненные стрелы
			return 0.98f;
		case 215754713: // костяные стрелы
			return 0.72f;
		case -1685290200: // дробь 12 калибра
			return 0.06f;
		case 588596902: // самодельные патроны
			return 0.07f;
		case -727717969: // пуля 12 калибра
			return 1.28f;
		case -1036635990: // зажигательные 12 калибра
			return 0.15f;
		case -2097376851: // гвозди
			return 0.7f;
		default:
			return 1.f;
		}
	}

	void Prediction(Vector local, Vector& target, Vector targetvel, float bulletspeed, float gravity) {
		float Dist = local.get_3d_dist(target);
		float BulletTime = Dist / bulletspeed;

		Vector vel = Vector(targetvel.x, 0, targetvel.z) * 0.75f;

		Vector PredictVel = vel * BulletTime;

		target += PredictVel;

		double height = target.y - local.y;
		Vector dir = target - local;
		float DepthPlayerTarget = my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(dir.x) + powFFFFFFFFFFFFFFFFFFFFFF(dir.z));

		float drop = CalcBulletDrop(height, DepthPlayerTarget, bulletspeed, gravity);

		target.y += drop;
	}
	/*void hk_serverrpc_playerprojectileattack(int64_t rcx, int64_t rdx, int64_t r9, int64_t _ppa, int64_t arg5) {

	}*/
	void hk_serverrpc_projectileshoot(int64_t rcx, int64_t rdx, int64_t r9, int64_t projectileShoot, int64_t arg5) {

		Vector rpc_position;
		float time = get_fixedTime();
		float travel_t = 0.f;

		do {
			if (!local_player)
				break;
			bool local_players = false;
		
			auto weapon = local_player->get_active_weapon();
			const int ammo = weapon->LoadedAmmo();

			if (!weapon)
				break;
			bool baseprojectiles = false;
			auto baseprojectile = local_player->get_active_weapon()->get_base_projetile();

			if (!baseprojectile)
				break;

			if (!vars::stor::closestPlayer)
				break;
			const auto stats = baseprojectile->get_stats(weapon->get_item_definition_id());

			auto wep_class_name = *(const char**)(*(uintptr_t*)(uintptr_t)baseprojectile + 0x10);
			if (*(int*)(wep_class_name + 4) == 'eleM' || *(int*)(wep_class_name) == 'ddaP')
				break;
			bool wep_class_names = false;

			bool projectile_lists = false;
			BaseProjectile* projectile_list = *reinterpret_cast<BaseProjectile**>(*reinterpret_cast<uintptr_t*>((uintptr_t)baseprojectile + 0x398) + 0x10); //createdProjectiles;

			esp::matrix = unity::get_view_matrix();
			auto camera_pos = unity::get_camera_pos();

			
			aim_target target = local_player->get_aimbot_target(camera_pos);
			
			bool shoot_lists = false;
			uintptr_t shoot_list = *(uintptr_t*)(*(uintptr_t*)(projectileShoot + 0x18) + 0x10);

			auto size = *(int*)(*(uintptr_t*)(projectileShoot + 0x18) + 0x18);
			
			Vector aimbot_velocity = Vector(0, 0, 0);
			Vector original_vel{};


			Vector aim_angle;
			Vector target_velocity, target_pos;
			if (vars::weapon::psilent && target.player && vars::stor::closestPlayer)
			{
				target_pos = target.player->get_bone_transform(48)->get_bone_position();
				target_pos.y += 0.1f;
				target_velocity = target.player->get_new_velocity();
			}
			for (int i = 0; i < size; i++) {
				auto projectileshoot = *(uintptr_t*)(shoot_list + 0x20 + i * 0x8);
				rpc_position = *reinterpret_cast<Vector*>(projectileshoot + 0x14);
				original_vel = *reinterpret_cast<Vector*>(projectileshoot + 0x20);

			 

				if (vars::weapon::manipulator && (unity::GetKey(rust::classes::KeyCode::Mouse4) && vars::stor::closestPlayer))
				{
					auto b = rpc_position;
					if (best_lean != Vector(0, 0, 0))
					{
						 
						rpc_position += (best_lean);
						if (rpc_position != b)
						{
							 
							*reinterpret_cast<Vector*>(projectileshoot + 0x14) = rpc_position;
						 
						}
					}
				}
			}

			for (int i = 0; i < projectile_list->get_size(); i++ )
			{
				auto projectile = *(BaseProjectile**)((uintptr_t)projectile_list + 0x20 + i * 0x8);
				 

	

				 
					 if (vars::weapon::psilent && target.player && vars::stor::closestPlayer) {
						 auto partialTime = projectile->partialTime();
						 auto travel = 0.f;
						 auto vel = (getmodifiedaimcone(0, rpc_position - target_pos, true)).Normalized() * original_vel.Length();
						 auto drag = projectile->drag();
						 auto grav = projectile->gravityModifier();
						 auto gravity = get_gravity();
						 auto deltatime = get_deltaTime();
						 auto timescale = get_timeScale();
						 auto offset = 0.1f;
						 int simulations = 0;
						 auto targetvel = target.player->get_new_velocity();
						 //travel_t = 0.f;

						 while (simulations < 3000) {
							 auto pos = rpc_position;
							 auto origin = pos;
							 float num = deltatime * timescale;
							 float travelTime = 0.f;
							 int num3 = (int)(8.f / num);

							 Vector vt = target_pos + Vector(0, offset, 0);
							 auto _aimdir = getmodifiedaimcone(0.f, vt - rpc_position, true);
							 auto velocity = _aimdir.Normalized() * original_vel.Length();



							 for (size_t i = 0; i < num3; i++)
							 {
								 origin = pos;
								 pos += velocity * num;
								 velocity += gravity * grav * num;
								 velocity -= velocity * drag * num;
								 travel_t += num;

								 if (LineCircleIntersection(target_pos, 0.1f, origin, pos, offset))
								 {

									 aimbot_velocity = (_aimdir).Normalized() * original_vel.Length();

									 aimbot_velocity += gravity * grav * num;
									 aimbot_velocity -= aimbot_velocity * drag * num;
									 break;
								 }

							 }
							 offset += 0.01f;
							 simulations++;
							 if (!aimbot_velocity.is_empty())
								 break;
						 }



					  
				}

				break;
			}

			for (int i = 0; i < size; i++) {
				auto projectile = *(uintptr_t*)(shoot_list + 0x20 + i * 0x8);
				if (target.player && vars::stor::closestPlayer || vars::manipulated && vars::stor::closestPlayer ||  autoshot && vars::stor::closestPlayer)  {

					*reinterpret_cast<Vector*>(projectile + 0x20) = aimbot_velocity; //startvel
				}
			}
		 
			float travel_t = 0.f;
 			for (int i = 0; i < projectile_list->get_size(); i++) {
				auto projectile = *(BaseProjectile**)((uintptr_t)projectile_list + 0x20 + i * 0x8);
				if (!projectile)
					continue;
				if (vars::weapon::nospread) {

					auto ItemModProjectile = projectile->get_item_mod_projectile();

					ItemModProjectile->projectileSpread() = -1;
					ItemModProjectile->projectileVelocitySpread() = -1;
				}
				if (vars::weapon::bullet_tp)
				{
					Vector r = rpc_position;
					Vector v = aimbot_velocity;
					Vector n = rpc_position + (aimbot_velocity * vars::desyncTime);
					//projectile->SetInitialDistance(r.distance(n));

					projectile->SetInitialDistance(r.distance(n) - 2.f); //1m then 2m?
		
				}
				else projectile->SetInitialDistance(0);
				 
			 
				 if (vars::weapon::psilent && vars::stor::closestPlayer) {
					

						 projectile->set_current_velocity(aimbot_velocity);
						 
						 if (vars::manipulated) {
							 auto g = get_gameObject((uintptr_t)projectile);
							 auto t = get_game_object_transform(g);
							 set_position(t, rpc_position);
						 }
					 
				 }
				 if(vars::stor::closestPlayer)
				 {
					 projectile->set_Initial_Velocity(aimbot_velocity);
				 }
				
				 
			}
		} while (0);

		reinterpret_cast<void (*)(int64_t, int64_t, int64_t, int64_t, int64_t)>(hooks::orig::serverrpc_projectileshoot)(rcx, rdx, r9, projectileShoot, arg5);
		fixed_time_last_shot = get_fixedTime();
		just_shot = true;
		did_reload = false;

	}

	bool is_lagging;

	bool flying = false, is_speeding = false;

	float nextActionTime = 0, period = 1.4721;

	uintptr_t client_entities;
	void OnAttacked(void* ssds, HitTest* hit_info) {
		shot_record_t shot_record_t;


		shoot_i++;
		if (shoot_i < 100)
			shoot_arr[shoot_i] = shot_record_t;
		else shoot_i = 0;
		if (vars::weapon::bullet_tracers)
		{
			Vector curpos = Vector(local_player->get_player_model2()->position().x, local_player->get_player_model2()->position().y + 1.7f, local_player->get_player_model2()->position().z);
			Line(curpos, hit_info->get_hitPositionWorld(), col(0, 162, 255, 75), 3.f, false, true);
		}




		return orig::OnAttacked(ssds, hit_info);
	}
	

	void hk_dofixedupdate(playerwalkmovement* base_movement, modelstate* modelstate) {
		float speed = (safe_read(base_movement + 0x146, bool) /*swim*/ || safe_read(base_movement + 0x44, float) /* crouch */ > 0.5f) ? 1.7f : (safe_read(base_movement + 0x148, bool) /*jump*/ ? 8.f : 5.5f);// playermovmen
		Vector vel = safe_read(base_movement + 0x34, Vector);
		speed = max(speed, vel.Length());
		if (vars::misc::always_sprint) {
			float len = vel.Length();
			if (len > 0.f) {
				vel = Vector(vel.x / len * speed, vel.y, vel.z / len * speed);
				safe_write(base_movement + 0x34, vel, Vector);
			}
			modelstate->set_flag(rust::classes::ModelState_Flag::Sprinting);
		}
		
	/*	if (vars::misc::AutoFarmBot) {

			if (vars::visuals::stone_ore)
			{
				Vector vel = safe_read(base_movement + 0x34, Vector);
				AimResult closest = AimResult::get_closest_object(local_player->get_bone_transform(48)->get_bone_position(), _("stone-ore.prefab"));
				if (closest.valid) {
					Vector direction = (closest.pos - local_player->get_bone_transform(48)->get_bone_position()).Normalized() * speed;
					safe_write(base_movement + 0x34, Vector(direction.x, vel.y, direction.z), Vector);
				}
			}
			else if (vars::visuals::metal_ore)
			{
				Vector vel = safe_read(base_movement + 0x34, Vector);
				AimResult closest = AimResult::get_closest_object(local_player->get_bone_transform(48)->get_bone_position(), _("metal-ore.prefab"));
				if (closest.valid) {
					Vector direction = (closest.pos - local_player->get_bone_transform(48)->get_bone_position()).Normalized() * speed;
					safe_write(base_movement + 0x34, Vector(direction.x, vel.y, direction.z), Vector);
				}
			}
			else if (vars::visuals::sulfur_ore)
			{
				Vector vel = safe_read(base_movement + 0x34, Vector);
				AimResult closest = AimResult::get_closest_object(local_player->get_bone_transform(48)->get_bone_position(), _("sulfur-ore.prefab"));
				if (closest.valid) {
					Vector direction = (closest.pos - local_player->get_bone_transform(48)->get_bone_position()).Normalized() * speed;
					safe_write(base_movement + 0x34, Vector(direction.x, vel.y, direction.z), Vector);
				}
			}

		}*/

		orig::DoFixedUpdate(base_movement, modelstate);
	}

	void hk_blocksprint(BasePlayer* player, float duration) {
		if (!vars::misc::jump_shoot)
			return hooks::orig::blocksprint(player, duration);

		return;
	}

	 

	//void hk_LaunchProjectile(BaseProjectile* p)
	//{
	//	auto recreation = [&]() {

	//		auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)p + primaryMagazine);
	//		auto ammo = *reinterpret_cast<int*>((uintptr_t)mag + 0x20); //ItemDefinition ammoType 0x20;
	//		int numprojectiles = 1;
	//	};

	//	//if (manual) {
	//	//	auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)p + primaryMagazine);
	//	//	auto c = *reinterpret_cast<int*>((uintptr_t)mag + 0x1C); //0x1C = public int contents;
	//	//	*reinterpret_cast<int*>((uintptr_t)mag + 0x1C) = (c - 1);

	//	//	updateammodisplay((uintptr_t)p);
	//	//	shot_fired((uintptr_t)p);
	//	//	did_attack_client_side((uintptr_t)p);
	//	//	manual = false;
	//	//}

	//	return orig::baseprojectile_launchprojectile((uintptr_t)p);
	//}

	void hk_playerwalkmovement_ClientInput(playerwalkmovement* player_walk_movement, uintptr_t inputstate, modelstate* model_state) {
		orig::playerwalkmovement_client_input(player_walk_movement, inputstate, model_state);

		set_sprinting(model_state, true);

		//player_walk_movement->noclip();



		//flying = player_walk_movement->get_flying();

		 
		
		if (vars::misc::flyhack_stop)
		{
			Vector curr = local_player->get_player_model2()->position();
			Vector old = cLastTickPos;
			Vector v4 = (curr - cLastTickPos);
			Vector ov = Vector(curr.x, curr.y, curr.z);

			if (vars::flyhack >= 2.3f)
				ov = Vector(ov.x, curr.y < old.y ? (curr.y - 0.3f) : old.y, ov.z);
			if (vars::hor_flyhack >= 6.f)
				ov = Vector(old.x, ov.y, old.z);

			if (vars::flyhack >= 2.3f
				|| vars::hor_flyhack >= 6.f) {
				if (ov != curr)
					//player_walk_movement->teleport_to(curr, local_player);
					player_walk_movement->set_TargetMovement(Vector(0, 0, 0));
			}
		}

		model_state->remove_flag(rust::classes::ModelState_Flag::Flying);
		auto wpn = local_player->get_active_weapon();
		auto held = wpn ? wpn->get_base_projetile() : nullptr;
		//if (vars::weapon::silent_reload && held) {
		//	time_since_last_shot = (get_fixedTime() - fixed_time_last_shot);
		//	vars::time_since_last_shot = time_since_last_shot;
		//	if (just_shot && (time_since_last_shot > 0.2f))
		//	{
		//		ServerRPC((uintptr_t)held, rust::classes::string(_(L"StartReload")));
		//		//esp::local_player->SendSignalBroadcast(rust::classes::Signal::Reload); //does this cause animation? YES
		//		just_shot = false;
		//	}
		//	float reloadtime = held->get_reload_time();
		//	esp::rl_time = reloadtime;

		//	if (time_since_last_shot > reloadtime * 0.95f //-10% for faster reloads than normal >:)
		//		&& !did_reload)
		//	{
		//		ServerRPC((uintptr_t)held, rust::classes::string(_(L"Reload")));
		//		did_reload = true;
		//		time_since_last_shot = 0;
		//	}
		//}
		//else
		//{
		//	time_since_last_shot = 0;
		//}
	}

	uintptr_t do_fixed_update_ptr, client_input_ptr, doOnAttac, StartCoroutine_ptr;

	float flyhackDistanceVertical = 0.f;
	float flyhackDistanceHorizontal = 0.f;
	float flyhackPauseTime;
	void TestFly() {
		flyhackPauseTime = max(0.f, flyhackPauseTime - get_deltaTime());
		bool inAir = false;
		float radius = local_player->GetRadius();
		float height = local_player->GetHeight(false);
		Vector vector = (local_player->lastSentTick()->position() + local_player->get_player_model2()->position()) * 0.5f;
		Vector vector2 = vector + Vector(0.f, radius - 2.f, 0.f);
		Vector vector4 = vector + Vector(0.f, height - radius, 0.f);
		float radius2 = radius - 0.05f;
		bool capsule = CheckCapsule(vector2, vector4, radius2, 1503731969, rust::classes::QueryTriggerInteraction::Ignore);
		inAir = !capsule;
		if (inAir) {
			bool flag = false;

			Vector vector4 = local_player->get_player_model2()->position() - local_player->lastSentTick()->position();
			float num3 = abs(vector4.y);
			float num4 = vector4.Magnitude2D();
			if (vector4.y >= 0.f) {
				flyhackDistanceVertical += vector4.y;
				flag = true;
			}
			if (num3 < num4) {
				flyhackDistanceHorizontal += num4;
				flag = true;
			}
			if (flag) {
				float num5 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num6 = local_player->GetJumpHeight_() + num5;
				float num7 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num8 = 5.f + num7;
			}
		}
		else {
			flyhackDistanceHorizontal = 0.f;
			flyhackDistanceVertical = 0.f;
		}
	}
	void hk_baseplayer_ClientInput(BasePlayer* baseplayer, input_state* state/*, Projectile* prj*/) {
		if (!do_fixed_update_ptr)
			do_fixed_update_ptr = mem::hook_virtual_function(_("PlayerWalkMovement"), _("DoFixedUpdate"), &hk_dofixedupdate);
		 
		if (!client_input_ptr)
			client_input_ptr = mem::hook_virtual_function(_("PlayerWalkMovement"), _("ClientInput"), &hk_playerwalkmovement_ClientInput);
		if (!doOnAttac)
			doOnAttac = mem::hook_virtual_function(_("BasePlayer"), _("OnAttacked"), &hooks::OnAttacked);
	 
		static uintptr_t* serverrpc_projecshoot;
		 //MrYasin This Need Fix


	 
		auto wpn = baseplayer->get_active_weapon();
		auto held = wpn ? wpn->get_base_projetile() : nullptr;

		if (baseplayer) {
			
			if (vars::visuals::hand_chams) {
				auto MrYasin = il2cpp::init_class(("Graphics"), ("ConVar"));
				auto static_fields = safe_read(MrYasin + 0xb8, uintptr_t);
				safe_write(static_fields + 0x75, false, bool);
			}
			 
			
			if (vars::gongetflyhack) {
				TestFly();
				float num5 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num6 = 3.f + num5;
				vars::max_flyhack = num6;
				if (flyhackDistanceVertical <= num6) {
					vars::flyhack = flyhackDistanceVertical;
				}

				float num7 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num8 = 6.f + num7;
				vars::max_hor_flyhack = num8;
				if (flyhackDistanceHorizontal <= num8) {
					vars::hor_flyhack = flyhackDistanceHorizontal;
				}
				if (flyhackDistanceVertical > num6) {
					baseplayer->get_movement2()->groundAngle(Vector(0, 0, 0));
					baseplayer->get_movement2()->groundAngleNew228(Vector(0, 0, 0));
					baseplayer->get_movement2()->TargetMovementk__BackingField(Vector(0, 0, 0));
				}

				if (flyhackDistanceHorizontal > num8) {
					baseplayer->get_movement2()->groundAngle(Vector(0, 0, 0));
					baseplayer->get_movement2()->groundAngleNew228(Vector(0, 0, 0));
					baseplayer->get_movement2()->TargetMovementk__BackingField(Vector(0, 0, 0));
				}
			}

		
			
			 
			
			if (vars::misc::rayleigh_changer) {
				reinterpret_cast<void(__fastcall*)(float)>(mem::game_assembly_base + CO::set_rayleigh)(vars::misc::rayleigh);
			}
			else {
				reinterpret_cast<void(__fastcall*)(float)>(mem::game_assembly_base + CO::set_rayleigh)(vars::misc::rayleigh);
			}
			if (vars::misc::mie_changer) {
				reinterpret_cast<void(__fastcall*)(float)>(mem::game_assembly_base + CO::set_mie)(vars::misc::mie);
			}
			else {
				reinterpret_cast<void(__fastcall*)(float)>(mem::game_assembly_base + CO::set_mie)(vars::misc::mie);
			}
			if (vars::misc::brightness_changer) {
				reinterpret_cast<void(__fastcall*)(float)>(mem::game_assembly_base + CO::set_brightness)(vars::misc::brightness);
			}
			else {
				reinterpret_cast<void(__fastcall*)(float)>(mem::game_assembly_base + CO::set_brightness)(vars::misc::brightness);
			}

			if (vars::weapon::movement_line) {
				Line(baseplayer->get_player_model2()->position(), baseplayer->lastSentTick()->position(), col(118, 124, 184, 1), 1.5f, true, true);
			}
			
			auto camera_pos = unity::get_camera_pos();
			aim_target target = local_player->get_aimbot_target(camera_pos);
			auto fixed_time = get_fixedTime();
			auto tick_time = baseplayer->get_last_sent_ticket_time();

		
			vars::desyncTime = (unity::get_realtimesincestartup() - tick_time) - 0.03125 * 3;
			if (vars::weapon::manipulator && held && wpn)
			{
				 
				float mm_eye = ((0.01f + ((vars::desyncTime + 2.f / 60.f + 0.125f) * baseplayer->MaxVelocity())));
				auto getammo = [&](BaseProjectile* held) {
					if (held) {
						auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)held + primaryMagazine);
						if (!mag) return 0;
						return *reinterpret_cast<int*>((uintptr_t)mag + 0x1C); //0x1C = public int contents;
					}
				};

				auto mag_ammo = getammo(held);
				if (vars::weapon::manipulator && (unity::GetKey(rust::classes::KeyCode::Mouse4)) && held && wpn )
				{

					float nextshot = fixed_time_last_shot + held->get_repeat_delay();
					if (can_manipulate(baseplayer,  mm_eye) && vars::desyncTime > 0.40f)//test
					{
						if (nextshot < fixed_time && (held->get_time_since_deploy() > held->get_deploy_delay() && mag_ammo > 0)) {

							//	vis_fat = true;
							vars::manipulated = true;
							if (vars::weapon::autoshoot)
							{
								launchprojectile((uintptr_t)held);
								updateammodisplay((uintptr_t)held);
								shot_fired((uintptr_t)held);
								did_attack_client_side((uintptr_t)held);
								typedef void(__fastcall* MrYasin)(BaseProjectile*, rust::classes::Signal, rust::classes::string);
								((MrYasin)(mem::game_assembly_base + O::BaseEntity::SendSignalBroadcast))(held, rust::classes::Signal::Attack, _(L""));
							}
							baseplayer->send_client_tick();
						}

					}

				}
				else vars::manipulated = false;
			}

			weapon* weapon_1 = local_player->get_active_weapon();
			DWORD64 _active = mem::read<DWORD64>((DWORD64)weapon_1 + O::Item::heldEntity);

			char* classname = weapon_1->ClassName();
			auto weaponmelee = weapon_1 && classname && (m_strstr(classname, _("BaseMelee")) || m_strstr(classname, _("Jackhammer")));
			
			//if (vars::misc::AutoFarmTree) {
			//	if (weaponmelee) {
			//		AimResult tree_entity = AimResult::get_closest_object(local_player->GetBoneByID(head),
			//			_(""),
			//			Vector::Zero(),
			//			Vector::Zero(),
			//			Vector::Zero(),
			//			true,
			//			_("TreeEntity"));
			//		if (tree_entity.valid) {

			//			AimResult tree_marker = AimResult::get_closest_object(local_player->GetBoneByID(head),
			//				_(""),
			//				Vector::Zero(),
			//				Vector::Zero(),
			//				Vector::Zero(),
			//				true,
			//				_("TreeMarker"));

			//			tree_entity.pos = Vector::Zero();
			//			if (tree_marker.valid) {
			//				Vector locala = utils::ClosestPoint(local_player, tree_marker.pos);
			//				if (Calc3D_Dist(locala, tree_marker.pos) <= 3.f) {
			//					tree_entity.pos = tree_marker.pos;
			//					Vector local = utils::ClosestPoint(local_player, tree_entity.pos);
			//					if (Calc3D_Dist(local, tree_entity.pos) <= 3.f) {
			//						DoMeleeAttack(tree_entity, _active, false);
			//					}
			//				}
			//			}

			//		}
			//	}
			//}
			//if (vars::misc::AutoFarmOre) {
			//	if (weaponmelee) {
			//		AimResult tree_entity = AimResult::get_closest_object(local_player->GetBoneByID(head),
			//			_(""),
			//			Vector::Zero(),
			//			Vector::Zero(),
			//			Vector::Zero(),
			//			true,
			//			_("OreHotSpot"));
			//		if (tree_entity.valid) {

			//			AimResult tree_marker = AimResult::get_closest_object(local_player->GetBoneByID(head),
			//				_(""),
			//				Vector::Zero(),
			//				Vector::Zero(),
			//				Vector::Zero(),
			//				true,
			//				_("OreHotSpot"));

			//			tree_entity.pos = Vector::Zero();
			//			if (tree_marker.valid) {
			//				Vector locala = utils::ClosestPoint(local_player, tree_marker.pos);
			//				if (Calc3D_Dist(locala, tree_marker.pos) <= 3.f) {
			//					tree_entity.pos = tree_marker.pos;
			//					Vector local = utils::ClosestPoint(local_player, tree_entity.pos);
			//					if (Calc3D_Dist(local, tree_entity.pos) <= 3.f) {
			//						DoMeleeAttack(tree_entity, _active, false);
			//					}
			//				}
			//			}

			//		}
			//	}
			//}
			
			if (vars::weapon::manipulator && unity::GetKey(rust::classes::KeyCode::Mouse4)) {

				baseplayer->set_client_tick_interval(0.99f);
			}
			else {
				baseplayer->set_client_tick_interval(0.01f);
			}
			auto baseprojectile = local_player->get_active_weapon();
			DWORD64 active = baseprojectile->entity();
		 

			if (vars::misc::attack_on_mountables) {
				auto mountable = baseplayer->get_mountable();
				if (mountable)
					mountable->canwielditem() = true;
			}

			bool kyslol = false;

		
			if (vars::misc::TakeFallDamage && unity::GetKey(rust::classes::KeyCode::P)) {
				OnLand(baseplayer, -8.0001f - 100);
			}
			if (vars::misc::admin_mode)
				baseplayer->set_admin_flag(rust::classes::PlayerFlags::IsAdmin);

			if (vars::misc::spiderman && vars::misc::Movement) {
				baseplayer->SpiderMan();
			}
			if (vars::misc::flyhack)
			{
				

				auto movement = baseplayer->get_movement();
				auto modelstate = baseplayer->get_model_state();
				
			}
			if (vars::misc::playerfovtoggle) {
				baseplayer->fov();
			}
			/*if (vars::misc::interactive_debug)
			{
				baseplayer->debugcamera();
			}*/
			 
			if (vars::visuals::Day) {
				baseplayer->Admintime();
			}
			else vars::visuals::DayTime = -1;
			baseplayer->todsky();

			//if (held) {
			//	if (!LI_FIND(strcmp)(held->get_class_name(), _("Planner"))) {
			//		auto planner = reinterpret_cast<Planner*>(held);
			//		if (unity::GetKeyDown(rust::classes::KeyCode::RightArrow))
			//		{
			//			auto v = planner->rotationoffset();
			//			planner->rotationoffset(Vector(v.x, v.y += 10, v.z));
			//		}
			//		else if (unity::GetKeyDown(rust::classes::KeyCode::LeftArrow))
			//		{
			//			auto v = planner->rotationoffset();
			//			planner->rotationoffset(Vector(v.x, v.y -= 10, v.z));
			//		}
			//	}
			//}

			/*if (!keybinds::fakelagb || unity::GetKey(keybinds::fakelagk)) {
				if (!is_lagging && !flying && vars::misc::fake_lag && !is_speeding) {
					baseplayer->set_client_tick_interval(0.5f);
					is_lagging = true;
				}
			}
			else if (is_lagging && flying || is_lagging && is_speeding) {
				local_player->set_client_tick_interval(0.03f);
				is_lagging = false;
			}
			else if (is_lagging && !vars::misc::fake_lag) {
				local_player->set_client_tick_interval(0.03f);
				is_lagging = false;
			}*/

			if (auto movement = baseplayer->get_movement()) {
				if (vars::misc::spiderman) {
					movement->set_ground_angles_new(0);
				}
			}

			if (vars::misc::eyeoffset) {
				baseplayer->Giraffe();
			}
			//playerwalkmovement* a1;
			//if (vars::misc::spiderman)
			//{
			//	a1->SetPinosScale(0.44);
			//}
		
			if (auto movement = baseplayer->get_movement()) {
				if (vars::misc::infinite_jump) {
					movement->set_land_time(0);
					movement->set_jump_time(0);
					movement->set_ground_time(100000);
				}

				if (vars::misc::gravity && vars::misc::Movement)
					movement->set_gravity_multiplier(vars::misc::gravity_modifier);
				else
					movement->set_gravity_multiplier(2.5f);

				if (vars::misc::jump_shoot) {
					if (auto modelstate = baseplayer->get_model_state()) {
						modelstate->set_flag(rust::classes::ModelState_Flag::OnGround);
						mem::write<float>((uint64_t)movement + O::BaseMovement::Groundedk__BackingField, 1); //private float <Grounded>k__BackingField; // 0x4C
					}
				}
				 
			}

			auto item = baseplayer->get_active_weapon();

			/*if (!keybinds::speedhackb || unity::GetKey(keybinds::speedhackk)) {
				if (vars::misc::speedhack && vars::misc::Movement) {
					set_timeScale(vars::misc::speedhackspeed);
					is_speeding = true;
				}
			}

			else if (!keybinds::speedkeyb || unity::GetKey(rust::classes::KeyCode::Mouse0)) {
				if (vars::weapon::fastshoot) {
					set_timeScale(1.2);
					is_speeding = true;
				}
			}
			else {
				set_timeScale(1);
				is_speeding = false;
			}*/
			float time = get_fixedTime();
			if (item) {
				auto baseprojectile = item->get_base_projetile();
				if (baseprojectile) {
				/*	for (int i = 0; i < 32; i++) {
						auto current = fired_projectiles[i];
						if (current.fired_at <= 2.f)
							continue;

						auto projectile = current.original;
						if (!projectile->authoritative())
							continue;

						float offset = 0.f;
						auto target = current.player;
						
					}*/
					weapon* proj = baseplayer->get_active_weapon();
					 
						BaseProjectile* held = proj->get_base_projetile();
						 
					/*if (vars::weapon::instakill && unity::GetKey(rust::classes::KeyCode::Mouse4) ) {

						baseplayer->set_client_tick_interval(0.99f);
						auto desyncTime = unity::get_realtimesincestartup() - local_player->Time();
						auto desnycPercentage = ((desyncTime / 0.99f) * 100.0f) + 1.f;
						vars::weapon::instatime = desyncTime;
						if (desnycPercentage > vars::weapon::instatimeshoot * 10)
						{
							baseprojectile->LaunchProjectile();
							typedef void(__fastcall* fakeshoot)(BaseProjectile*, rust::classes::Signal, rust::classes::string);
							((fakeshoot)(mem::game_assembly_base + O::BaseEntity::SendSignalBroadcast))(held, rust::classes::Signal::Attack, _(L""));
						}

					}*/
					auto wep_class_name = *(const char**)(*(uintptr_t*)(uintptr_t)baseprojectile + 0x10);
					if (!(*(int*)(wep_class_name + 4) == 'eleM' && *(int*)(wep_class_name) == 'esaB')) {
						




						if (*(int*)(wep_class_name) == 'esaB' && *(int*)(wep_class_name + 4) == 'jorP' || *(int*)(wep_class_name) == 'nilF') {
							if (item->is_weapon()) {
								const auto item_id = item->get_item_definition_id();
								DWORD64 heldentity = item->entity();

								switch (item_id) {
								case -75944661:
									if (vars::weapon::eoka) {
										mem::write<bool>((uint64_t)baseprojectile + 0x3B0, true); //_didSparkThisFrame
										mem::write<float>((uint64_t)baseprojectile + 0x3A0, 1.f); //success fraction
									}
									break;
								default:
									
									if (vars::weapon::automatic)
										baseprojectile->is_automatic() = true;
									if (vars::weapon::nospread)
										baseprojectile->set_no_spread();
									if (vars::weapon::norecoil)
										baseprojectile->set_recoil(0, 0, 0, 0);
									if (vars::weapon::nosway)
										baseprojectile->set_no_sway();
									if (vars::weapon::rapid_fire)
										mem::write<float>(heldentity + repeatDelay, 0.02f);
									else
										mem::write<float>(heldentity + repeatDelay, 0.13);
									break;
								}
							}
						}
					}
				}
			}

		
			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::Water, !vars::misc::no_playercollision);
			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::Tree, vars::misc::no_playercollision);
			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::AI, vars::misc::no_playercollision);

			draw_get();

			if (tick_time > gui::tick_time_when_called + 10) {
				unity::camera = unity::get_main_camera();
				gui::tick_time_when_called = tick_time;
			}
		}

		orig::baseplayer_client_input(baseplayer, state);

		 

		auto model_state = baseplayer->get_model_state();

		bool targeted = false;
		float target_time = 0.f;
		if (get_fixedTime() > (target_time + 0.1f) && target_time != 0.0f && targeted)
		{
			target_time = 0.0f;
			targeted = false;
		}

		auto current = safe_read(state + 0x10, uintptr_t); if (!current) { return orig::baseplayer_client_input(baseplayer, state); }
		if (!current)
			return orig::baseplayer_client_input(baseplayer, state);
		Vector real_angles = safe_read(current + 0x18, Vector);
		Vector spin_angles = Vector::Zero();

		int jitter = 1;
		int jitter_speed = 10;

		if (vars::misc::spinbot)
		{
			spin_angles = Vector((my_rand() % 999 + -999), (my_rand() % 999 + -999), (my_rand() % 999 + -999));

		}
		if (spin_angles != Vector::Zero())
			safe_write(current + 0x18, spin_angles, Vector);

	}

}