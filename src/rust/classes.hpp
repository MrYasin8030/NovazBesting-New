#pragma once
//#include "../vars.hpp"
//#include "unity.hpp"
//#include "../utils/xor_float.hpp"
#include <basetsd.h>
#include "../utils/xor_float.hpp"
typedef struct _UncStr {
	char stub[0x10];
	int len;
	wchar_t str[1];
}*pUncStr;
struct Ammo {
	int id[2];
	float speed;
};
struct Weapon {
	int id;
	const char* name;
	Ammo ammo[4];
	int category; //-3 - hammer, -2 - bows, -1 - eoka, 0-nopatch, 1 - meele, 2 - semiautomatic, 3 - automatic
};
Weapon Info[]{
Weapon{1588298435, ("Bolt Action Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375.f}, Ammo{{1712070256} /*HV 5.56*/, 788 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 394}}, 2 },
Weapon{-778367295, ("L96 Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 625.f}, Ammo{{1712070256} /*HV 5.56*/, 1350 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 675}}, 2 },

Weapon{-1367281941, ("Waterpipe Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 185.f}, Ammo{{588596902, -1036635990}/*gray, blue*/, 80}}, 2 },
Weapon{-765183617, ("Double Barrel Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 185.f}, Ammo{{588596902, -1036635990}/*gray, blue*/, 80}}, 2 },
Weapon{-41440462, ("Spas-12 Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 185.f}, Ammo{{588596902, -1036635990}/*gray, blue*/, 80}}, 2 },
Weapon{795371088, ("Pump Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 185.f}, Ammo{{588596902, -1036635990}/*gray, blue*/, 80}}, 2 },
Weapon{-75944661, ("Eoka Pistol"), { Ammo{{-727717969, -1685290200}/*green, red*/, 185.f}, Ammo{{588596902, -1036635990}/*gray, blue*/, 80}}, -1 },

Weapon{1965232394, ("Crossbow"), { Ammo{{-1234735557}/*normal arrow*/, 78.f}, Ammo{{14241751} /*fire arrow*/, 61.f}, Ammo{{215754713} /*bone arrow*/, 66.f}, Ammo{{-1023065463} /*HV arrow*/, 120.f}}, 2 },
Weapon{884424049, ("Compound Bow"), { Ammo{{-1234735557}/*normal arrow*/, 50.f}, Ammo{{14241751} /*fire arrow*/, 40}, Ammo{{215754713} /*bone arrow*/, 45}, Ammo{{-1023065463} /*HV arrow*/, 78.8f}}, 2 }, //TODO on zoom velocity x2
Weapon{1443579727, ("Hunting Bow"), { Ammo{{-1234735557}/*normal arrow*/, 50.f}, Ammo{{14241751} /*fire arrow*/, 40}, Ammo{{215754713} /*bone arrow*/, 45}, Ammo{{-1023065463} /*HV arrow*/, 80} }, -2 },

Weapon{1318558775, ("MP5A4"), { Ammo{{785728077}/*normal pistol*/, 190.f}, Ammo{{-1691396643} /*HV pistol*/, 290.f}, Ammo{{51984655} /*inc pistol*/, 145.f}}, 3 },
Weapon{1796682209, ("Custom SMG"), { Ammo{{785728077}/*normal pistol*/, 205.f}, Ammo{{-1691396643} /*HV pistol*/, 300.f}, Ammo{{51984655} /*inc pistol*/, 145.f}}, 3 },
Weapon{649912614, ("Revolver"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{818877484, ("Semi-Automatic Pistol"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{-852563019, ("M92 Pistol"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{1373971859, ("Python Revolver"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol 225*/, 225}}, 2 },
Weapon{-1758372725, ("Thompson"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 3 },

Weapon{-1812555177, ("LR-300 Assault Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },
Weapon{-904863145, ("Semi-Automatic Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 2 },
Weapon{1545779598, ("Assault Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },
Weapon{-1335497659, ("Assault Rifle Ice"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },
Weapon{-2069578888, ("M249"), { Ammo{{-1211166256}/*normal 5.56*/, 375.f}, Ammo{{1712070256} /*HV 5.56*/, 585 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 293}}, 3 },
Weapon{-1214542497, ("HMLMG"), { Ammo{{-1211166256}/*normal 5.56*/, 375.f}, Ammo{{1712070256} /*HV 5.56*/, 585 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 293}}, 3 },
Weapon{28201841, ("M39 Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 469}, Ammo{{1712070256} /*HV 5.56*/, 563 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 281}}, 2 },

Weapon{1090916276, ("Pitchfork"), {Ammo{{0}, 25}}, 1 },
Weapon{1540934679, ("Wooden Spear"), {Ammo{{0}, 25}}, 1 },
Weapon{1814288539, ("Bone Knife"), {Ammo{{0}, 20}}, 1 },
Weapon{-363689972, ("Snowball"), {Ammo{{0}, 20}}, 1 },
Weapon{1789825282, ("Candy Cane Club"), {Ammo{{0}, 20}}, 1 },
Weapon{-1137865085, ("Machete"), {Ammo{{0}, 20}}, 1 },
Weapon{1711033574, ("Bone Club"), {Ammo{{0}, 20}}, 1 },
Weapon{-1966748496, ("Mace"), {Ammo{{0}, 18}}, 1 },
Weapon{-194509282, ("Butcher Knife"), {Ammo{{0}, 20}}, 1 },
Weapon{1326180354, ("Salvaged Sword"), {Ammo{{0}, 20}}, 1 },
Weapon{-1469578201, ("Longsword"), {Ammo{{0}, 18}}, 1 },
Weapon{-1978999529, ("Salvaged Cleaver"), {Ammo{{0}, 18}}, 1 },
Weapon{1602646136, ("Stone Spear"), {Ammo{{0}, 30}}, 1 },
Weapon{2040726127,("Combat Knife"), {Ammo{{0}, 30}}, 1 },
Weapon{963906841, ("Rock"), {Ammo{{0}, 18}}, 1 },

Weapon{1953903201, ("Nailgun"), { Ammo{{-2097376851}/*nails*/, 50}}, 2 },
Weapon{-1123473824, ("Multiple Grenade Launcher"), { Ammo{{915408809, 349762871}/*smoke, exp*/, 100}, Ammo{{1055319033}, 225}/*shotgun*/}, 2 },
Weapon{442886268, ("Rocket Launcher"), 0, 69 },
Weapon{-1215753368, ("Flame Thrower"), 0, 0 },
Weapon{200773292, ("Hammer"), {0}, -3 }
};
enum BoneList : int
{

	helli = -742865266,
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	engine_col,
	patrol_helicopter,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};

class col {
public:
	float r;
	float g;
	float b;
	float a;

	col()
	{
		r = 0;
		g = 0;
		b = 0;
		a = 0;
	}

	col(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	col GetUnityColor()
	{
		return col(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}
};
uintptr_t _displayName = il2cpp::value(_("BasePlayer"), _("_displayName"));
uintptr_t woundedlol = il2cpp::value(_("BasePlayer"), _("Wounded"));
uintptr_t movement = il2cpp::value(_("BasePlayer"), _("movement"));
uintptr_t player_inventory = il2cpp::value(_("BasePlayer"), _("inventory"));
uintptr_t clActiveItem = il2cpp::value(_("BasePlayer"), _("clActiveItem"));
uintptr_t playerModel = il2cpp::value(_("BasePlayer"), _("playerModel"));
//uintptr_t clientTeam = il2cpp::value(_("BasePlayer"), _("clientTeam"));
uintptr_t playerFlags = il2cpp::value(_("BasePlayer"), _("playerFlags"));
//uintptr_t clientTickInterval = il2cpp::value(_("BasePlayer"), _("clientTickInterval"));
uintptr_t eyes = il2cpp::value(_("BasePlayer"), _("eyes"));
uintptr_t lastSentTickTime = il2cpp::value(_("BasePlayer"), _("lastSentTickTime"));
uintptr_t modelState = il2cpp::value(_("BasePlayer"), _("modelState"));
uintptr_t input = il2cpp::value(_("BasePlayer"), _("input"));
uintptr_t containerBelt = il2cpp::value(_("PlayerInventory"), _("containerBelt"));
uintptr_t containerWear = il2cpp::value(_("PlayerInventory"), _("containerWear"));
uintptr_t itemList = il2cpp::value(_("ItemContainer"), _("itemList"));
uintptr_t userID = il2cpp::value(_("BasePlayer"), _("userID"));
uintptr_t mounted = il2cpp::value(_("BasePlayer"), _("mounted"));
uintptr_t clientTickInterval = il2cpp::value(_("BasePlayer"), _("clientTickInterval"));
uintptr_t newVelocity = il2cpp::value(_("PlayerModel"), _("newVelocity"));
uintptr_t isLocalPlayer = il2cpp::value(_("PlayerModel"), _("isLocalPlayer"));

uintptr_t _health = il2cpp::value(_("BaseCombatEntity"), _("_health"));
uintptr_t _maxHealth = il2cpp::value(_("BaseCombatEntity"), _("_maxHealth"));
uintptr_t lifestate = il2cpp::value(_("BaseCombatEntity"), _("lifestate"));

uintptr_t net = il2cpp::value(_("BaseNetworkable"), _("net"));

uintptr_t heldEntity = il2cpp::value(_("Item"), _("heldEntity"));

uintptr_t canWieldItems = il2cpp::value(_("BaseMountable"), _("canWieldItems"));

uintptr_t recoil = il2cpp::value(_("BaseProjectile"), _("recoil"));
uintptr_t automatic = il2cpp::value(_("BaseProjectile"), _("automatic"));

uintptr_t aimSway = il2cpp::value(_("BaseProjectile"), _("aimSway"));
uintptr_t aimSwaySpeed = il2cpp::value(_("BaseProjectile"), _("aimSwaySpeed"));
uintptr_t primaryMagazine = il2cpp::value(_("BaseProjectile"), _("primaryMagazine"));

uintptr_t aimCone = il2cpp::value(_("BaseProjectile"), _("aimCone"));
uintptr_t hipAimCone = il2cpp::value(_("BaseProjectile"), _("hipAimCone"));
uintptr_t aimConePenaltyMax = il2cpp::value(_("BaseProjectile"), _("aimConePenaltyMax"));
uintptr_t aimconePenaltyPerShot = il2cpp::value(_("BaseProjectile"), _("aimconePenaltyPerShot"));
uintptr_t stancePenaltyScale = il2cpp::value(_("BaseProjectile"), _("stancePenaltyScale"));

uintptr_t successFraction = il2cpp::value(_("FlintStrikeWeapon"), _("successFraction"));
uintptr_t didSparkThisFrame = il2cpp::value(_("FlintStrikeWeapon"), _("_didSparkThisFrame"));
uintptr_t initialVelocity = il2cpp::value(_("Projectile"), _("initialVelocity"));
uintptr_t currentVelocity = il2cpp::value(_("Projectile"), _("currentVelocity"));
uintptr_t currentPosition = il2cpp::value(_("Projectile"), _("currentPosition"));
uintptr_t thickness_addr = il2cpp::value(_("Projectile"), _("thickness"));
//uintptr_t projectileVelocityScale_addr = il2cpp::value(_("BaseProjectile"), _("projectileVelocityScale"));
uintptr_t mod = il2cpp::value(_("Projectile"), _("mod"));
uintptr_t hitTest = il2cpp::value(_("Projectile"), _("hitTest"));

uintptr_t damageProperties = il2cpp::value(_("BaseMelee"), _("damageProperties"));

uintptr_t weakspots = il2cpp::value(_("BaseHelicopter"), _("weakspots"));

uintptr_t info = il2cpp::value(_("Item"), _("info"));

uintptr_t iconSprite = il2cpp::value(_("ItemDefinition"), _("iconSprite"));
//uintptr_t steamItem = il2cpp::value(_("ItemDefinition"), _("steamItem"));

uintptr_t category = il2cpp::value(_("ItemDefinition"), _("category"));
uintptr_t itemid = il2cpp::value(_("ItemDefinition"), _("itemid"));
uintptr_t displayName = il2cpp::value(_("ItemDefinition"), _("displayName"));

uintptr_t viewOffset = il2cpp::value(_("PlayerEyes"), _("viewOffset"));

uintptr_t swimming = il2cpp::value(_("PlayerWalkMovement"), _("swimming"));

uintptr_t lastHitTime = il2cpp::value(_("Chainsaw"), _("lastHitTime"));
uintptr_t lastHitMaterial = il2cpp::value(_("Chainsaw"), _("lastHitMaterial"));
uintptr_t gathering = il2cpp::value(_("BaseMelee"), _("gathering"));

uintptr_t nextAttackTime = il2cpp::value(_("AttackEntity"), _("nextAttackTime"));
uintptr_t timeSinceDeploy = il2cpp::value(_("AttackEntity"), _("timeSinceDeploy"));
uintptr_t deployDelay = il2cpp::value(_("AttackEntity"), _("deployDelay"));
uintptr_t repeatDelay = il2cpp::value(_("AttackEntity"), _("repeatDelay"));
uintptr_t TargetMovement = il2cpp::value(_("BaseMovement"), _("<TargetMovement>k__BackingField"));

uintptr_t groundAngleNew = il2cpp::value(_("PlayerWalkMovement"), _("groundAngleNew"));
uintptr_t landTime = il2cpp::value(_("PlayerWalkMovement"), _("landTime"));
uintptr_t jumpTime = il2cpp::value(_("PlayerWalkMovement"), _("jumpTime"));
uintptr_t groundTime = il2cpp::value(_("PlayerWalkMovement"), _("groundTime"));
uintptr_t gravityMultiplier = il2cpp::value(_("PlayerWalkMovement"), _("gravityMultiplier"));
uintptr_t flying = il2cpp::value(_("PlayerWalkMovement"), _("flying"));

uintptr_t model = il2cpp::value(_("BaseEntity"), _("model"));




class BaseProjectile;

class transform;

class BasePlayer;
class PlayerEyes;
class HitTest;
class modelstate;

typedef struct Str
{
	char stub[0x10];
	int len;
	wchar_t str[1];
} *str;

class weapon;

//static auto GetIndex = reinterpret_cast<int(*)(uintptr_t SkinSetCollection, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinSetCollection"), _("GetIndex"), 1, _(""), _(""))));

//static auto Movement_Walking = reinterpret_cast<void(*)(modelstate*, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("Movement_Walking"), 1, _(""), _(""))));

static auto GetWorldVelocity = reinterpret_cast<Vector(*)(BasePlayer * base_entity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));

static auto HasPlayerFlag = reinterpret_cast<bool(*)(BasePlayer*, rust::classes::PlayerFlags)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("HasPlayerFlag"), 1, _(""), _(""))));

static auto get_game_object_transform = reinterpret_cast<transform * (*)(uintptr_t game_object)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("get_transform"), 0, _(""), _("UnityEngine"))));

static auto get_iconSprite = reinterpret_cast<uintptr_t(*)(weapon * Item)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));

static auto get_texture = reinterpret_cast<uintptr_t(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));

static auto get_rect = reinterpret_cast<rust::classes::Rect(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_rect"), 0, _(""), _("UnityEngine"))));

//static auto StringPool_Get = reinterpret_cast<unsigned int(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("StringPool"), _("Get"), 1, _("str"), _(""))));

//static auto set_timeScale = reinterpret_cast<void(*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("set_timeScale"), 1, _(""), _("UnityEngine"))));

static auto get_timeScale = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_timeScale"), 0, _(""), _("UnityEngine"))));

//static auto FindBone = reinterpret_cast<transform * (*)(BasePlayer*, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("FindBone"), 1, _(""), _(""))));

static auto get_mousePosition = reinterpret_cast<Vector(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("GetMouseButton"), 0, _(""), _("UnityEngine"))));

static auto GetMouseButton = reinterpret_cast<bool(*)(int(*))>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("get_mousePosition"), 0, _(""), _("UnityEngine"))));

static auto teleportto = reinterpret_cast<void(*)(uintptr_t, Vector, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("TeleportTo"), 0, _(""), _(""))));

//static auto FloorToInt = reinterpret_cast<int (*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Mathf"), _("FloorToInt"), 1, _(""), _("UnityEngine"))));

static auto get_gravity = reinterpret_cast<Vector(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("get_gravity"), 1, _(""), _("UnityEngine"))));

//static auto get_isAlive = reinterpret_cast<bool (*)(BaseProjectile*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAlive"), 0, _(""), _(""))));

static auto get_position = reinterpret_cast<Vector(*)(uintptr_t transform)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_position"), 0, _(""), _("UnityEngine"))));

//static auto get_scale = reinterpret_cast<Vector(*)(uintptr_t transform)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_localScale"), 0, _(""), _("UnityEngine"))));

static auto get_up = reinterpret_cast<Vector(*)(transform*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_up"), 0, _(""), _("UnityEngine"))));

static auto Find = reinterpret_cast<uintptr_t(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));

//static auto set_hideFlags = reinterpret_cast<void(*)(uintptr_t material, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_hideFlags"), 1, _(""), _("UnityEngine"))));

//static auto set_name = reinterpret_cast<void(*)(uintptr_t, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_name"), 1, _(""), _("UnityEngine"))));
static auto launchprojectile = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));

static auto updateammodisplay = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0, _(""), _(""))));

static auto shot_fired = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("ShotFired"), 0, _(""), _(""))));

static auto did_attack_client_side = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DidAttackClientside"), 0, _(""), _(""))));

static auto SetInt = reinterpret_cast<void(*)(uintptr_t material, rust::classes::string name, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetInt"), 1, _(""), _("UnityEngine"))));

static auto get_deltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_deltaTime"), 0, _(""), _("UnityEngine"))));

static auto get_IsNpc = reinterpret_cast<bool(*)(uintptr_t player_model)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerModel"), _("get_IsNpc"), -1, _(""), _(""))));

//static auto Abs_fn = reinterpret_cast<float(*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Mathf"), _("Abs"), 1, _(""), _("UnityEngine"))));

static auto get_time = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_time"), 0, _(""), _("UnityEngine"))));

static auto ClosestPoint = reinterpret_cast<Vector(*)(BasePlayer*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ClosestPoint"), 1, _("position"), _(""), 1)));

//static auto InverseTransformPoint = reinterpret_cast<Vector(*)(transform*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformPoint"), 1, _(""), _("UnityEngine"))));

//static auto InverseTransformDirection = reinterpret_cast<Vector(*)(transform*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformDirection"), 1, _(""), _("UnityEngine"))));

static auto get_transform = reinterpret_cast<transform * (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));

 auto get_gameObject = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_gameObject"), 0, _(""), _("UnityEngine"))));

static auto set_position = reinterpret_cast<void(*)(transform*, Vector value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_position"), 1, _(""), _("UnityEngine"))));

//static auto GetMaxSpeed = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMaxSpeed"), 1, _(""), _(""))));

//static auto LookRotation = reinterpret_cast<vector4(*)(Vector, Vector value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Quaternion"), _("LookRotation"), 2, _(""), _("UnityEngine"))));

//static auto set_rotation = reinterpret_cast<void(*)(transform*, vector4 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_rotation"), 1, _(""), _("UnityEngine"))));

//static auto set_localscale = reinterpret_cast<void(*)(transform*, Vector value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localScale"), 1, _(""), _("UnityEngine"))));

//static auto StartAttackCooldown = reinterpret_cast<void(*)(BaseProjectile*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("StartAttackCooldown"), 1, _(""), _(""))));

//static auto ProcessAttack = reinterpret_cast<void(*)(BaseProjectile*, HitTest*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));

static auto GetProjectileVelocityScale = reinterpret_cast<float(*)(BaseProjectile*, bool max)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetProjectileVelocityScale"), 1, _("getMax"), _(""), 1)));

static auto get_Renderers = reinterpret_cast<rust::list<uintptr_t>*(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));

static auto get_material = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));

static auto SetColor = reinterpret_cast<void(*)(uintptr_t material, rust::classes::string name, col value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetColor"), 2, _("name"), _("UnityEngine"), 1)));

static auto FindShader = reinterpret_cast<uintptr_t(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));

static auto get_fixedTime = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_fixedTime"), 0, _(""), _("UnityEngine"))));

static auto PEyes_get_rotation = reinterpret_cast<vector4(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_rotation"), 0, _(""), _(""))));
static auto LoadAsset = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, rust::classes::string path, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAsset_Internal"), 2, _("name"), _("UnityEngine"), 1)));

static auto PEyes_get_position = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_position"), 0, _(""), _(""))));
static auto getmodifiedaimcone = reinterpret_cast<Vector(*)(float, Vector, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AimConeUtil"), _("GetModifiedAimConeDirection"), 0, _(""), _(""))));

static auto SendClientTick = reinterpret_cast<void(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("SendClientTick"), 0, _(""), _(""))));

//static auto updateammodisplay = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0, _(""), _(""))));

//static auto shot_fired = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("ShotFired"), 0, _(""), _(""))));

//static auto did_attack_client_side = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DidAttackClientside"), 0, _(""), _(""))));

//static auto MovementRight = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("MovementRight"), 0, _(""), _(""))));
//
//static auto headforward = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("HeadForward"), 0, _(""), _(""))));
//
//static auto bodyforward = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("BodyForward"), 0, _(""), _(""))));
//
// 
//static auto MovementForward = reinterpret_cast<Vector(*)(PlayerEyes*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("MovementForward"), 0, _(""), _(""))));
static auto get_maxspeed = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMaxSpeed"), 0, _(""), _(""))));
//static auto GetParentVelocity = reinterpret_cast<Vector(*)(BasePlayer * base_entity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetParentVelocity"), 0, _(""), _(""))));
static auto BoundsPadding = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("BoundsPadding"), 2, _(""), _(""))));
static auto GetJumpHeight = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetJumpHeight"), 0, _(""), _(""))));

static auto get_components_in_children = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponentsInChildren"), 0, _(""), _("UnityEngine"))));

//static auto set_localScale = reinterpret_cast<uintptr_t(*)(transform*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localScale"), 2, _(""), _("UnityEngine"))));

//static auto get_trasform_fn = reinterpret_cast<transform * (*)(void*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), -1, _(""), _("UnityEngine"))));

float current_time;
static auto Sphere = reinterpret_cast<void (*)(Vector vPos, float fRadius, col color, float fDuration, bool distanceFade)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Box"), 5, _(""), _("UnityEngine"))));
static auto Line = reinterpret_cast<void (*)(Vector, Vector, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));
static auto Arrow = reinterpret_cast<void (*)(Vector, Vector, float, col, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Arrow"), 6, _(""), _("UnityEngine"))));

static auto HitNormalWorld = reinterpret_cast<Vector(*)(uintptr_t)>(0);
static auto HitPointWorld = reinterpret_cast<Vector(*)(uintptr_t)>(0);

void init_bp() {
	HitPointWorld = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("HitTest"), _("HitPointWorld"), 0, _(""), _(""))));
	Sphere = reinterpret_cast<void (*)(Vector vPos, float fRadius, col color, float fDuration, bool distanceFade)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Box"), 5, _(""), _("UnityEngine"))));
	Line = reinterpret_cast<void (*)(Vector, Vector, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));
	Arrow = reinterpret_cast<void (*)(Vector, Vector, float, col, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Arrow"), 6, _(""), _("UnityEngine"))));
	 //Movement_Walking = reinterpret_cast<void(*)(modelstate*, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("Movement_Walking"), 1, _(""), _(""))));

	launchprojectile = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));

	updateammodisplay = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0, _(""), _(""))));

	shot_fired = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("ShotFired"), 0, _(""), _(""))));

	did_attack_client_side = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DidAttackClientside"), 0, _(""), _(""))));

	//set_onLadder = reinterpret_cast<void(*)(modelstate*, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_onLadder"), 1, _(""), _(""))));
	GetWorldVelocity = reinterpret_cast<Vector(*)(BasePlayer * base_entity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));
	HasPlayerFlag = reinterpret_cast<bool(*)(BasePlayer*, rust::classes::PlayerFlags)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("HasPlayerFlag"), 1, _(""), _(""))));
	get_game_object_transform = reinterpret_cast<transform * (*)(uintptr_t game_object)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("get_transform"), 0, _(""), _("UnityEngine"))));
	get_rect = reinterpret_cast<rust::classes::Rect(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_rect"), 0, _(""), _("UnityEngine"))));
	get_iconSprite = reinterpret_cast<uintptr_t(*)(weapon * Item)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));
	//steamItem = il2cpp::value(_("ItemDefinition"), _("steamItem"));
	iconSprite = il2cpp::value(_("ItemDefinition"), _("iconSprite"));
	LoadAsset = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, rust::classes::string path, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAsset_Internal"), 2, _("name"), _("UnityEngine"), 1)));

	get_texture = reinterpret_cast<uintptr_t(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));
	//set_name = reinterpret_cast<void(*)(uintptr_t, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_name"), 1, _(""), _("UnityEngine"))));;
	get_gameObject = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_gameObject"), 0, _(""), _("UnityEngine"))));
	//InverseTransformDirection = reinterpret_cast<Vector(*)(transform*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformDirection"), 1, _(""), _("UnityEngine"))));
	//LookRotation = reinterpret_cast<vector4(*)(Vector, Vector value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Quaternion"), _("LookRotation"), 2, _(""), _("UnityEngine"))));
	//set_rotation = reinterpret_cast<void(*)(transform*, vector4 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_rotation"), 1, _(""), _("UnityEngine"))));
	//set_localscale = reinterpret_cast<void(*)(transform*, Vector value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localScale"), 1, _(""), _("UnityEngine"))));
	set_position = reinterpret_cast<void(*)(transform*, Vector value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_position"), 1, _(""), _("UnityEngine"))));
	SetInt = reinterpret_cast<void(*)(uintptr_t material, rust::classes::string name, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetInt"), 1, _(""), _("UnityEngine"))));
	//set_hideFlags = reinterpret_cast<void(*)(uintptr_t material, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_hideFlags"), 1, _(""), _("UnityEngine"))));
	Find = reinterpret_cast<uintptr_t(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));
	SetColor = reinterpret_cast<void(*)(uintptr_t, rust::classes::string name, col value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetColor"), 2, _("name"), _("UnityEngine"), 1)));
	FindShader = reinterpret_cast<uintptr_t(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));
	get_Renderers = reinterpret_cast<rust::list<uintptr_t> *(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));
	get_material = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));
	//StringPool_Get = reinterpret_cast<unsigned int(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("StringPool"), _("Get"), 1, _("str"), _(""))));
	//set_timeScale = reinterpret_cast<void(*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("set_timeScale"), 1, _(""), _("UnityEngine"))));
	get_timeScale = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_timeScale"), 0, _(""), _("UnityEngine"))));
	//GetIndex = reinterpret_cast<int(*)(uintptr_t SkinSetCollection, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinSetCollection"), _("GetIndex"), 1, _(""), _(""))));
	//FloorToInt = reinterpret_cast<int (*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Mathf"), _("FloorToInt"), 1, _(""), _("UnityEngine"))));
	get_gravity = reinterpret_cast<Vector(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("get_gravity"), 1, _(""), _("UnityEngine"))));
	//FindBone = reinterpret_cast<transform * (*)(BasePlayer*, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("FindBone"), 1, _(""), _(""))));
	//get_isAlive = reinterpret_cast<bool (*)(BaseProjectile*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAlive"), 0, _(""), _(""))));
	GetMouseButton = reinterpret_cast<bool(*)(int(*))>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("GetMouseButton"), 0, _(""), _("UnityEngine"))));
	get_mousePosition = reinterpret_cast<Vector(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("get_mousePosition"), 0, _(""), _("UnityEngine"))));
	//GetMaxSpeed = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMaxSpeed"), 1, _(""), _(""))));
	teleportto = reinterpret_cast<void(*)(uintptr_t, Vector, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("TeleportTo"), 0, _(""), _(""))));
	clientTickInterval = il2cpp::value(_("BasePlayer"), _("clientTickInterval"));
	containerWear = il2cpp::value(_("PlayerInventory"), _("containerWear"));
	canWieldItems = il2cpp::value(_("BaseMountable"), _("canWieldItems"));
	mounted = il2cpp::value(_("BasePlayer"), _("mounted"));
	containerBelt = il2cpp::value(_("PlayerInventory"), _("containerBelt"));
	itemList = il2cpp::value(_("ItemContainer"), _("itemList"));
	weakspots = il2cpp::value(_("BaseHelicopter"), _("weakspots"));

	model = il2cpp::value(_("BaseEntity"), _("model"));
	gathering = il2cpp::value(_("BaseMelee"), _("gathering"));

	lastHitTime = il2cpp::value(_("Chainsaw"), _("lastHitTime"));
	lastHitMaterial = il2cpp::value(_("Chainsaw"), _("lastHitMaterial"));
	landTime = il2cpp::value(_("PlayerWalkMovement"), _("landTime"));
	jumpTime = il2cpp::value(_("PlayerWalkMovement"), _("jumpTime"));
	groundTime = il2cpp::value(_("PlayerWalkMovement"), _("groundTime"));
	gravityMultiplier = il2cpp::value(_("PlayerWalkMovement"), _("gravityMultiplier"));
	 TargetMovement = il2cpp::value(_("BaseMovement"), _("<TargetMovement>k__BackingField"));

	damageProperties = il2cpp::value(_("BaseMelee"), _("damageProperties"));
	movement = il2cpp::value(_("BasePlayer"), _("movement"));
	_displayName = il2cpp::value(_("BasePlayer"), _("_displayName"));
	player_inventory = il2cpp::value(_("BasePlayer"), _("inventory"));
	clActiveItem = il2cpp::value(_("BasePlayer"), _("clActiveItem"));
	playerModel = il2cpp::value(_("BasePlayer"), _("playerModel"));
	//clientTeam = il2cpp::value(_("BasePlayer"), _("clientTeam"));
	playerFlags = il2cpp::value(_("BasePlayer"), _("playerFlags"));
	//clientTickInterval = il2cpp::value(_("BasePlayer"), _("clientTickInterval"));
	eyes = il2cpp::value(_("BasePlayer"), _("eyes"));
	lastSentTickTime = il2cpp::value(_("BasePlayer"), _("lastSentTickTime"));
	modelState = il2cpp::value(_("BasePlayer"), _("modelState"));
	input = il2cpp::value(_("BasePlayer"), _("input"));
	userID = il2cpp::value(_("BasePlayer"), _("userID"));

	newVelocity = il2cpp::value(_("PlayerModel"), _("newVelocity"));
	isLocalPlayer = il2cpp::value(_("PlayerModel"), _("isLocalPlayer"));
	initialVelocity = il2cpp::value(_("Projectile"), _("initialVelocity"));
	nextAttackTime = il2cpp::value(_("AttackEntity"), _("nextAttackTime"));
	timeSinceDeploy = il2cpp::value(_("AttackEntity"), _("timeSinceDeploy"));
	deployDelay = il2cpp::value(_("AttackEntity"), _("deployDelay"));
	repeatDelay = il2cpp::value(_("AttackEntity"), _("repeatDelay"));

	_health = il2cpp::value(_("BaseCombatEntity"), _("_health"));
	_maxHealth = il2cpp::value(_("BaseCombatEntity"), _("_maxHealth"));
	lifestate = il2cpp::value(_("BaseCombatEntity"), _("lifestate"));

	net = il2cpp::value(_("BaseNetworkable"), _("net"));

	heldEntity = il2cpp::value(_("Item"), _("heldEntity"));

	recoil = il2cpp::value(_("BaseProjectile"), _("recoil"));
	automatic = il2cpp::value(_("BaseProjectile"), _("automatic"));

	aimSway = il2cpp::value(_("BaseProjectile"), _("aimSway"));
	aimSwaySpeed = il2cpp::value(_("BaseProjectile"), _("aimSwaySpeed"));
	primaryMagazine = il2cpp::value(_("BaseProjectile"), _("primaryMagazine"));

	aimCone = il2cpp::value(_("BaseProjectile"), _("aimCone"));
	hipAimCone = il2cpp::value(_("BaseProjectile"), _("hipAimCone"));
	aimConePenaltyMax = il2cpp::value(_("BaseProjectile"), _("aimConePenaltyMax"));
	aimconePenaltyPerShot = il2cpp::value(_("BaseProjectile"), _("aimconePenaltyPerShot"));
	stancePenaltyScale = il2cpp::value(_("BaseProjectile"), _("stancePenaltyScale"));

	currentVelocity = il2cpp::value(_("Projectile"), _("currentVelocity"));
	currentPosition = il2cpp::value(_("Projectile"), _("currentPosition"));
	thickness_addr = il2cpp::value(_("Projectile"), _("thickness"));
	mod = il2cpp::value(_("Projectile"), _("mod"));
	hitTest = il2cpp::value(_("Projectile"), _("hitTest"));

	info = il2cpp::value(_("Item"), _("info"));

	category = il2cpp::value(_("ItemDefinition"), _("category"));
	itemid = il2cpp::value(_("ItemDefinition"), _("itemid"));
	displayName = il2cpp::value(_("ItemDefinition"), _("displayName"));

	viewOffset = il2cpp::value(_("PlayerEyes"), _("viewOffset"));

	swimming = il2cpp::value(_("PlayerWalkMovement"), _("swimming"));
	groundAngleNew = il2cpp::value(_("PlayerWalkMovement"), _("groundAngleNew"));
	flying = il2cpp::value(_("PlayerWalkMovement"), _("flying"));

	
	
	
	HitNormalWorld = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("HitTest"), _("HitNormalWorld"), 0, _(""), _(""))));

	get_position = reinterpret_cast<Vector(*)(uintptr_t transform)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_position"), 0, _(""), _("UnityEngine"))));

	//get_scale = reinterpret_cast<Vector(*)(uintptr_t transform)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_localScale"), 0, _(""), _("UnityEngine"))));

	get_up = reinterpret_cast<Vector(*)(transform*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_up"), 0, _(""), _("UnityEngine"))));

	get_deltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_deltaTime"), 0, _(""), _("UnityEngine"))));

	get_IsNpc = reinterpret_cast<bool(*)(uintptr_t player_model)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerModel"), _("get_IsNpc"), -1, _(""), _(""))));

	//Abs_fn = reinterpret_cast<float(*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Mathf"), _("Abs"), 1, _(""), _("UnityEngine"))));

	get_time = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_time"), 0, _(""), _("UnityEngine"))));

	GetProjectileVelocityScale = reinterpret_cast<float(*)(BaseProjectile*, bool max)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetProjectileVelocityScale"), 1, _("getMax"), _(""), 1)));

	ClosestPoint = reinterpret_cast<Vector(*)(BasePlayer*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ClosestPoint"), 1, _("position"), _(""), 1)));

	//StartAttackCooldown = reinterpret_cast<void(*)(BaseProjectile*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("StartAttackCooldown"), 1, _(""), _(""))));

	get_transform = reinterpret_cast<transform * (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));

	//InverseTransformPoint = reinterpret_cast<Vector(*)(transform*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformPoint"), 1, _(""), _("UnityEngine"))));

	//ProcessAttack = reinterpret_cast<void(*)(BaseProjectile*, HitTest*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));

	get_fixedTime = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_fixedTime"), 0, _(""), _("UnityEngine"))));
	getmodifiedaimcone = reinterpret_cast<Vector(*)(float, Vector, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AimConeUtil"), _("GetModifiedAimConeDirection"), 0, _(""), _(""))));

	PEyes_get_rotation = reinterpret_cast<vector4(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_rotation"), 0, _(""), _(""))));

	PEyes_get_position = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_position"), 0, _(""), _(""))));

	SendClientTick = reinterpret_cast<void(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("SendClientTick"), 0, _(""), _(""))));

	//updateammodisplay = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0, _(""), _(""))));

	//shot_fired = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("ShotFired"), 0, _(""), _(""))));

	//did_attack_client_side = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DidAttackClientside"), 0, _(""), _(""))));

	//MovementRight = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("MovementRight"), 0, _(""), _(""))));

	//headforward = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("HeadForward"), 0, _(""), _(""))));

	//bodyforward = reinterpret_cast<Vector(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("BodyForward"), 0, _(""), _(""))));
	//MovementForward = reinterpret_cast<Vector(*)(PlayerEyes*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("MovementForward"), 0, _(""), _(""))));
	get_maxspeed = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMaxSpeed"), 0, _(""), _(""))));
//	GetParentVelocity = reinterpret_cast<Vector(*)(BasePlayer * base_entity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetParentVelocity"), 0, _(""), _(""))));
	BoundsPadding = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("BoundsPadding"), 2, _(""), _(""))));
	GetJumpHeight = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetJumpHeight"), 0, _(""), _(""))));

	get_components_in_children = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponentsInChildren"), 0, _(""), _("UnityEngine"))));

	//set_localScale = reinterpret_cast<uintptr_t(*)(transform*, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localScale"), 2, _(""), _("UnityEngine"))));

	//get_trasform_fn = reinterpret_cast<transform * (*)(void*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), -1, _(""), _("UnityEngine"))));
}

class transform {
public:
	


	Vector get_bone_position() {
		if (!(uintptr_t)this)
			return {};
		return get_position((uintptr_t)this);
	}

	Vector get_bone_position_up() {
		if (!(uintptr_t)this)
			return {};
		return get_up(this);
	}

	
};

class MonoBehaviour {
public:
	static inline rust::Object_* (*StartCoroutine_)(MonoBehaviour*, rust::Object_*) = nullptr;
	rust::Object_* StartCoroutine(rust::Object_* routine) 
	{
		return StartCoroutine_(this, routine);
	}

	transform* get_transform()
	{
		return *reinterpret_cast<transform**>((uintptr_t)this + 0x8);
	}
};

class BaseNetworkable : public MonoBehaviour {
public:
};

class BaseEntity : public BaseNetworkable {
public:
	Vector GetWorldVelocity() {
		if (!this) return Vector(0, 0, 0);
		auto off = reinterpret_cast<Vector(*)(BaseEntity*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));
		return off(this);
	}
	/*Vector GetParentVelocity() {
		if (!this) return Vector(0, 0, 0);
		auto off = reinterpret_cast<Vector(*)(BaseEntity*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetParentVelocity"), 0, _(""), _(""))));
		return off(this);
	}*/
};

class BaseCombatEntity : public BaseEntity {
public:
	float get_health() {
		return *reinterpret_cast<float*>((uintptr_t)this + _health);
	}
};

class item_mod_projectile {
public:
	float get_projectile_velocity() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x34);
	}

	float& projectileSpread() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x30);
	}

	float& projectileVelocitySpread() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x38);
	}
};

class BasePlayer;

class HitTest {
public:
	uintptr_t game_object() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x70);
	}
	Vector get_hitPositionWorld() {
		return *reinterpret_cast<Vector*>((uintptr_t)this + 0x54);
	}
	rust::classes::game_object* get_gameobject()
	{
		auto gameObject = game_object();
		if (!gameObject)
			return nullptr;

		return *reinterpret_cast<rust::classes::game_object**>(gameObject + 0x10);
	}
	BasePlayer*& get_hit_entity() {
		return *reinterpret_cast<BasePlayer**>((uintptr_t)this + 0x88);
	}
	void set_hit_entity(BasePlayer* entity) {
		*reinterpret_cast<BasePlayer**>((uintptr_t)this + 0x88) = entity;
	}
	void set_ignore_entity(BasePlayer* entity_to_ignore) {
		*reinterpret_cast<BasePlayer**>((uintptr_t)this + 0x80) = entity_to_ignore;
	}
};




class BaseProjectile {
public:
	//float projectilevel_scale = projectileVelocityScale();
	bool first = false;
	float thickness = 0;

	
	void partialTime(float f) { safe_write(this + 0xA4, f, float); }//public float tumbleSpeed; // 0xA4
	float partialTime() { return safe_read(this + 0xA4, float); }//public float tumbleSpeed; // 0xA4
	float drag() { return safe_read(this + 0x24, float); }
	float gravityModifier() { return safe_read(this + 0x28, float); }

	void set_last_hit_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + lastHitTime) = time;
	}
	void LaunchProjectile()
	{
		if (!this) return;
		return reinterpret_cast<void(__fastcall*)(BaseProjectile*)>(mem::game_assembly_base + O::BaseProjectile::LaunchProjectile)(this);
	}

	float SetInitialDistance(float d) { return safe_write(this + 0x30, d, float); }


	char* get_class_name() {
		auto bp = *reinterpret_cast<uintptr_t*>(this);
		return (char*)*reinterpret_cast<uintptr_t*>(bp + 0x10);
	}

	HitTest* get_hit_test() {
		return *reinterpret_cast<HitTest**>((uintptr_t)this + hitTest);
	}

	

	item_mod_projectile* get_item_mod_projectile() {
		return *reinterpret_cast<item_mod_projectile**>((uintptr_t)this + mod);
	}
	float get_deploy_delay() {
		return *reinterpret_cast<float*>((uintptr_t)this + deployDelay);
	}
	float get_time_since_deploy() {
		return *reinterpret_cast<float*>((uintptr_t)this + timeSinceDeploy);
	}
	float get_repeat_delay() {
		return *reinterpret_cast<float*>((uintptr_t)this + repeatDelay);
	}
	weapon_stats_t get_stats(int32_t weapon_id) {
		const auto primary_magazine = *reinterpret_cast<uintptr_t*>((uintptr_t)this + primaryMagazine);
		if (primary_magazine == 1)
			return weapon_stats_t{ xf(1000) };

		float velocity = xf(1000);
		float gravity_modifier = xf(1);
		float drag = xf(.001f);
		float distance = xf(0);

		auto velocity_scale = xf(1);
		bool scale_velocity = false;

		const auto ammo_definition = *reinterpret_cast<uintptr_t*>(primary_magazine + 0x20);
		if (ammo_definition) {
			// itemid
			const auto ammo_id = *reinterpret_cast<int32_t*>(ammo_definition + 0x18);

			switch (ammo_id) {
			case shotgun:
				velocity = xf(225);
				drag = xf(1);
				distance = xf(3);
				break;
			case shotgun_slug:
				velocity = xf(225);
				drag = xf(1);
				distance = xf(10);
				break;
			case shotgun_fire:
				velocity = 100;
				drag = 1;
				distance = 3;
				break;
			case shotgun_handmade:
				velocity = 100;
				drag = 1;
				distance = 0;
				break;
			case rifle_556:
				velocity = 375;
				drag = .6;
				distance = 15;
				break;
			case rifle_556_hv:
				velocity = 450;
				drag = .6;
				distance = 15;
				break;
			case rifle_556_fire:
				velocity = 225;
				drag = .6;
				distance = 15;
				break;
			case rifle_556_explosive:
				velocity = 225;
				gravity_modifier = 1.25;
				drag = .6;
				distance = 15;
				break;
			case pistol:
				velocity = 300;
				drag = .7;
				distance = 15;
				break;
			case pistol_hv:
				velocity = 400;
				drag = .7;
				distance = 15;
				break;
			case pistol_fire:
				velocity = 225;
				drag = .7;
				distance = 15;
				break;
			case arrow_wooden:
				velocity = 50;
				gravity_modifier = .75;
				drag = .005;
				break;
			case arrow_hv:
				velocity = 80;
				gravity_modifier = .5;
				drag = .005;
				break;
			case arrow_fire:
				velocity = 40;
				gravity_modifier = 1;
				drag = .01;
				break;
			case arrow_bone:
				velocity = 45;
				gravity_modifier = .75;
				drag = .01;
				break;
			case nailgun_nails:
				velocity = 50;
				gravity_modifier = .75;
				drag = .005;
				break;
			}

			scale_velocity = true;
			velocity_scale =
				GetProjectileVelocityScale(this, false);
		}

		switch (weapon_id) {
		case spear_wooden:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case spear_stone:
			velocity = 30;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		}

		if (scale_velocity && (velocity_scale != 0))
			velocity *= velocity_scale;

		return { velocity, gravity_modifier, drag, distance };
	}

	/*transform* get_transform_m() {
		if (!this) return nullptr;
		return get_trasform_fn(this);
	}*/

	Vector get_current_position() {
		return *reinterpret_cast<Vector*>((uintptr_t)this + currentPosition);
	}

	void set_projectile_thickness(float thickness)
	{
		*reinterpret_cast<float*>((uintptr_t)this + thickness_addr) = thickness;
	}

	float get_projectile_thickness()
	{
		return *reinterpret_cast<float*>((uintptr_t)this + thickness_addr);
	}

	/*float& projectileVelocityScale()
	{
		return *reinterpret_cast<float*>((uintptr_t)this + projectileVelocityScale_addr);
	}*/

	void set_current_velocity(Vector position)
	{
		*reinterpret_cast<Vector*>((uintptr_t)this + currentVelocity) = position;
	}

	void set_Initial_Velocity(Vector pos)
	{
		*reinterpret_cast<Vector*>((uintptr_t)this + initialVelocity) = pos;
	}

	uint32_t get_size() { return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }

	void set_recoil(float yaw_min, float yaw_max, float pitch_min, float pitch_max) {
		auto recoil_properties = *reinterpret_cast<uintptr_t*>((uintptr_t)this + recoil);

		float recoilx = vars::weapon::recoilx;
		 

		auto new_recoil_properties = *reinterpret_cast<uintptr_t*>((uintptr_t)recoil_properties + 0x78);

		if (new_recoil_properties)
		{
			*reinterpret_cast<float*>(new_recoil_properties + 0x18) = recoilx;
			*reinterpret_cast<float*>(new_recoil_properties + 0x1C) = recoilx;
			*reinterpret_cast<float*>(new_recoil_properties + 0x20) = -recoilx;
			*reinterpret_cast<float*>(new_recoil_properties + 0x24) = -recoilx;
			//*reinterpret_cast<float*>(new_recoil_properties + 0x2C) = 9999.f; //timeToTakeMax
			//*reinterpret_cast<float*>(new_recoil_properties + 0x30) = 0.f; //ADSScale
		}
		else
		{
			*reinterpret_cast<float*>(recoil_properties + 0x18) = recoilx; //recoilYawMin 
			*reinterpret_cast<float*>(recoil_properties + 0x1C) = recoilx; //recoilYawMax 
			*reinterpret_cast<float*>(recoil_properties + 0x20) = -recoilx; //recoilPitchMin 
			*reinterpret_cast<float*>(recoil_properties + 0x24) = -recoilx; //recoilPitchMax 
			//*reinterpret_cast<float*>(recoil_properties + 0x2C) = 9999.f; //timeToTakeMax
			//*reinterpret_cast<float*>(recoil_properties + 0x30) = 0.f; //ADSScale
		}
	}

	void set_no_sway() {
		*reinterpret_cast<float*>((uintptr_t)this + aimSway) = 0;
		*reinterpret_cast<float*>((uintptr_t)this + aimSwaySpeed) = 0;
	}

	bool& is_automatic() {
		return *reinterpret_cast<bool*>((uintptr_t)this + automatic);
	}

	void set_no_spread(float scale = 0.f) {
		auto recoil_properties = *reinterpret_cast<uintptr_t*>((uintptr_t)this + recoil);
		auto new_recoil_properties = *reinterpret_cast<uintptr_t*>((uintptr_t)recoil_properties + 0x78);
		*reinterpret_cast<float*>((uintptr_t)this + aimCone) = scale;
		*reinterpret_cast<float*>((uintptr_t)this + hipAimCone) = scale;
		*reinterpret_cast<float*>((uintptr_t)this + aimConePenaltyMax) = scale;
		*reinterpret_cast<float*>((uintptr_t)this + aimconePenaltyPerShot) = scale;
		*reinterpret_cast<float*>((uintptr_t)this + stancePenaltyScale) = scale;

		if (new_recoil_properties)
			*reinterpret_cast<float*>(new_recoil_properties + 0x60) = scale; //aimconeCurveScale
		else *reinterpret_cast<float*>(recoil_properties + 0x60) = scale; //aimconeCurveScale
	}
	
	
	

	 
};

class PlayerNameID {
public:
	wchar_t* get_username() {
		auto username = (str)(*reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x18));

		return username->str;
	}

	unsigned long get_user_id()
	{
		return *reinterpret_cast<unsigned long*>((uintptr_t)this + 0x20);
	}
};

class weapon {
public:
	uintptr_t entity() {
		return mem::read<uintptr_t>((uintptr_t)this + O::Item::heldEntity);
	}
	uintptr_t get_icon_sprite() {
		const auto     item_definition = mem::read<uintptr_t>((uintptr_t)this + info);
		if (!item_definition)
			return 0;

		return *reinterpret_cast<uintptr_t*>(item_definition + iconSprite);
	}

	char* ClassName() {
		return (char*)safe_read(safe_read(safe_read(this + O::Item::heldEntity, DWORD64), DWORD64) + 0x10, DWORD64);
	}

	//uintptr_t get_steam_icon_sprite() {
	//	const auto     item_definition = mem::read<uintptr_t>((uintptr_t)this + info);
	//	if (!item_definition)
	//		return 0;

	//	auto SteamInventoryItem = *reinterpret_cast<uintptr_t*>(item_definition + steamItem);
	//	if (!SteamInventoryItem)
	//		return 0;

	//	return *reinterpret_cast<uintptr_t*>(SteamInventoryItem + 0x20);
	//}

	int GetAmount()
	{
		return *reinterpret_cast<int*>(this + 0x30);
	}
	wchar_t* get_weapon_name() {
		auto item_def = *reinterpret_cast<uintptr_t*>((uintptr_t)this + info);
		if (!item_def)
			return {};

		auto display_name = *reinterpret_cast<uintptr_t*>(item_def + displayName);
		if (!display_name)
			return {};

		auto weapon_name = (str)(*reinterpret_cast<uintptr_t*>(display_name + 0x18));

		return weapon_name->str;
	}

	bool is_weapon() {
		const auto     item_definition = mem::read<uintptr_t>((uintptr_t)this + info);
		if (!item_definition)
			return false;

		return mem::read<uint32_t>(item_definition + category) == 0;
	}

	int32_t get_item_definition_id()
	{
		const auto     item_definition = *reinterpret_cast<uintptr_t*>((uintptr_t)this + info);
		if (!item_definition)
			return 0;

		return *reinterpret_cast<int32_t*>(item_definition + itemid);
	}

	BaseProjectile* get_base_projetile() {
		return *reinterpret_cast<BaseProjectile**>((uintptr_t)this + heldEntity);
	}

	int GetID()
	{
		const auto Info = mem::read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x18);
		const int ID = mem::read<int>(Info + 0x18);
		return ID;
	}
	Weapon Infos() {
		int ID = GetID();
		for (Weapon k : Info) {
			if (k.id == ID) {
				return k;
			}
		}
		return Weapon{ 0 };
	}
	int LoadedAmmo()
	{
		const auto Held = mem::read<DWORD64>(reinterpret_cast<uintptr_t>(this) + 0xA8); // private EntityRef heldEntity;
		if (Held <= 0)
			return 0;
		const auto Magazine = mem::read<DWORD64>(Held + primaryMagazine);
		if (Magazine <= 0 || Magazine == 0x3F000000)
		{
			return 0;
		}
		const auto ammoType = mem::read<DWORD64>(Magazine + 0x20);
		if (ammoType <= 0 || ammoType == 0x3F000000)
		{
			return 0;
		}
		const int ammo = mem::read<int>(ammoType + 0x18);
		return ammo;
	}
};

class modelstate {
public:
	

	void remove_flag(rust::classes::ModelState_Flag flag) {
		int flags = *reinterpret_cast<int*>((uintptr_t)this + 0x20);
		flags &= ~(int)flag;

		*reinterpret_cast<int*>((uintptr_t)this + 0x20) = flags;
	}

	void set_flag(rust::classes::ModelState_Flag flag) {
		int flags = *reinterpret_cast<int*>((uintptr_t)this + 0x20);

		*reinterpret_cast<int*>((uintptr_t)this + 0x20) = flags |= (int)flag;
	}

	bool has_flag(rust::classes::ModelState_Flag f)
	{
		int& flags = *reinterpret_cast<int*>((uintptr_t)this + 0x20);

		return (flags & (int)f) == (int)f;
	}
};

class playerwalkmovement {
public:
	void TargetMovementk__BackingField(Vector d) {
		*reinterpret_cast<Vector*>((uintptr_t)this + O::BaseMovement::TargetMovementk__BackingField) = d;
	}

	void groundAngleNew228(Vector d) {
		*reinterpret_cast<Vector*>((uintptr_t)this + O::PlayerWalkMovement::groundAngleNew) = d;
	}

	void groundAngle(Vector d) {
		*reinterpret_cast<Vector*>((uintptr_t)this + O::PlayerWalkMovement::groundAngle) = d;
	}
	uintptr_t GetCapsule() {

		static UINT_PTR amongasik = 0x402402;

		if (amongasik == 0x402402)
		{
			amongasik = 0xB0;//PlayerWalkMovement.capsule
		}

		return *(uintptr_t*)(this + amongasik);


		return 0;
	}
	void SetPinosScale(float wtox1cf_rad) { //IM FULL FIXED THIS!                                                                                                                                                                  WTOX1CF#7077

		static UINT_PTR var = 0x402402;

		if (var == 0x402402)
		{
			var = 0x25A57D0; // CapsuleCollider.set_radius
		}

		typedef void amongasik(uintptr_t, float);
		((amongasik*)(mem::game_assembly_base + var))(GetCapsule(), wtox1cf_rad);


	}
	//void set_swimming(bool flag) {
	//	*reinterpret_cast<bool*>((uintptr_t)this + swimming) = flag;
	//}

	//bool get_admin_cheat() {
	//	return *reinterpret_cast<bool*>((uintptr_t)this + 0x18);
	//}

	//void set_admin_cheat(bool admin_cheat) {
	//	*reinterpret_cast<bool*>((uintptr_t)this + 0x18) = admin_cheat;
	//}

	//bool get_flying() {
	//	return *reinterpret_cast<bool*>((uintptr_t)this + flying);
	//}

	//void set_flying(bool fly) {
	//	*reinterpret_cast<bool*>((uintptr_t)this + flying) = fly;
	//}
	void set_TargetMovement(Vector v) {
		*reinterpret_cast<Vector*>((uintptr_t)this + TargetMovement) = v;
	}
	void teleport_to(Vector p, BasePlayer* ply) {
		return teleportto((uintptr_t)this, p, (uintptr_t)ply);
	}
	void set_ground_angles_new(float angle) {
		*reinterpret_cast<float*>((uintptr_t)this + groundAngleNew) = angle;
	}

	void set_land_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + landTime) = time;
	}

	void set_jump_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + jumpTime) = time;
	}

	void set_ground_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + groundTime) = time;
	}

	void set_gravity_multiplier(float multiplier) {
		*reinterpret_cast<float*>((uintptr_t)this + gravityMultiplier) = multiplier;
	}

	
};

auto cliententities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);

class networkable {
public:
	unsigned int get_id() {
		return *reinterpret_cast<unsigned int*>((uintptr_t)this + 0x10);
	}

	rust::list<uintptr_t>* GetComponentsInChildren(uintptr_t type) {
		if (!this || !type) return nullptr;
		return reinterpret_cast<rust::list<uintptr_t>*>(get_components_in_children((uintptr_t)this, type));
	}
};
 class aim_target {
public:
	Vector pos;

	BasePlayer* player = NULL;

	BaseCombatEntity* ent = NULL;
	BasePlayer* targeting = NULL;
	float distance = 200;
	float fov = vars::weapon::aimbotfov;

	int network_id;

	bool is_heli = false;
	bool visible = false;
	bool sleeping = false;
	bool teammate = false;
	bool found = false;

	Vector avg_vel = Vector(0, 0, 0);

	Vector velocity;

	bool operator<(const aim_target& b) {
		if (fov == vars::weapon::aimbotfov) {
			return distance < b.distance;
		}
		else {
			return fov < b.fov;
		}
	}
};

float get_2d_dist(const vector2& Src, const Vector& Dst) {
	return my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(Src.x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(Src.y - Dst.y));
}

class playereyes {
public:
	

	Vector get_view_offset() {
		return *reinterpret_cast<Vector*>((uintptr_t)this + viewOffset);
	}

	vector4 get_rotation() {
		if (!this) return vector4(0, 0, 0, 0);
		return PEyes_get_rotation((uintptr_t)this);
	}
	
	Vector get_position() {
		if (!this) return Vector(0, 0, 0);
		return PEyes_get_position((uintptr_t)this);
	}
	/*Vector body_forward() {
		if (!this) return Vector(0, 0, 0);
		return bodyforward((uintptr_t)this);
	}

	Vector get_right()
	{
		if (!(uintptr_t)this)
			return {};
		return MovementRight((uintptr_t)this);
	}

	Vector _bodyforward()
	{
		if (!(uintptr_t)this)
			return {};
		return bodyforward((uintptr_t)this);
	}

	Vector head_forward()
	{
		if (!(uintptr_t)this)
			return {};
		return headforward((uintptr_t)this);
	}*/
};

class input_state {
public:
	void set_aim_angles(Vector aim_angle) {
		auto current = mem::read<uintptr_t>((uintptr_t)this + 0x10);

		*reinterpret_cast<Vector*>(current + 0x18) = aim_angle;
	}
};

class basemountable {
public:
	bool& canwielditem() {
		return *reinterpret_cast<bool*>((uintptr_t)this + canWieldItems);
	}
};

class Object {

};

class Component : public Object {
public:
	transform* get_transform() {
		if (!this) return nullptr;
		auto off = reinterpret_cast<transform * (*)(Component*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
		return off(this);
	}
};

class Shader : public Object {
public:

};

class Material : public Object {
public:
	Shader* GetShader() {
		if (!this) return nullptr;
		auto off = reinterpret_cast<Shader * (*)(Material*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("get_shader"), 0, _(""), _("UnityEngine"))));
		return off(this);
	}
	void SetShader(Shader* s) {
		if (!this) return;
		auto off = reinterpret_cast<void(*)(Material*, Shader*)>(il2cpp::methods::resolve_icall(_("UnityEngine.Material::set_shader()")));
		return off(this, s);
	}
	void SetColor(rust::classes::string s, col c) {
		if (!this) return;
		auto off = reinterpret_cast<void(*)(Material*, rust::classes::string, col)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetColor"), 2, _("name"), _("UnityEngine"), 1)));
		return off(this, s, c);
	}
	void SetInt(rust::classes::string s, int c) {
		if (!this) return;
		auto off = reinterpret_cast<void(*)(Material*, rust::classes::string, int)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetInt"), 2, _("name"), _("UnityEngine"), 1)));
		return off(this, s, c);
	}
};

class Renderer : public Component {
public:
	Material* GetMaterial() {
		if (!this) return nullptr;
		auto off = reinterpret_cast<Material * (*)(Renderer*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));
		return off(this);
	}
	void SetMaterial(Material* value) {
		if (!this) return;
		auto off = reinterpret_cast<void(__fastcall*)(Renderer*, Material*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Renderer"), _("set_material"), 0, _(""), _("UnityEngine"))));
		return off(this, value);
	}
};

class SkinnedMultiMesh : public MonoBehaviour {
public:

	rust::list<Renderer*>* get_Renderers() {
		if (!this) return nullptr;
		auto off = reinterpret_cast<rust::list<Renderer*>*(*)(SkinnedMultiMesh*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));
		return off(this);
	}
};

class PlayerTick {
public:
	Vector position() {
		Vector th = mem::read<Vector>((uintptr_t)this + 0x18);
		if (!th.is_empty()) {
			return th;
		}
		else { return Vector(0.f, 0.f, 0.f); }
	}
};

class Player_Model {
public:
	SkinnedMultiMesh* _multiMesh() {
		return (SkinnedMultiMesh*)mem::read<DWORD64*>((uintptr_t)this + O::PlayerModel::_multiMesh);
	}
	Vector position() {
		return mem::read<Vector>((uintptr_t)this + O::PlayerModel::position);
	}
};

class PlayerEyes {
public:
	Quaternion get_rotation() {
		typedef Quaternion(__stdcall* get_rotation)(PlayerEyes*);
		Quaternion result = ((get_rotation)(mem::game_assembly_base + O::PlayerEyes::get_rotation))(this);
		return result;
	}

	/*void set_view_offset(Vector offset) {
		*reinterpret_cast<Vector*>((uintptr_t)this + viewOffset) = offset;
	}*/

	//Vector get_view_offset() {
	//	return *reinterpret_cast<Vector*>((uintptr_t)this + viewOffset);
	//}

	/*Vector center_eye()
	{
		if (!(uintptr_t)this)
			return {};
		return *reinterpret_cast<Vector*>((DWORD64)this + O::PlayerEyes::get_center);
	}*/

	//Vector get_right()
	//{
	//	if (!(uintptr_t)this)
	//		return {};
	//	return MovementRight((uintptr_t)this);
	//}

	//Vector head_forward()
	//{
	//	if (!(uintptr_t)this)
	//		return {};
	//	return headforward((uintptr_t)this);
	//}
	//Vector MovementForward_()
	//{
	//	if (!this) return Vector::Zero();
	//	return MovementForward(this);
	//}

	//Vector _bodyforward()
	//{
	//	if (!(uintptr_t)this)
	//		return {};
	//	return bodyforward((uintptr_t)this);
	//}
};
class ViewModel {
public:
};
class BasePlayer;
BasePlayer* local_player = 0;

class BasePlayer {
public:
	bool IsValid()
	{
		if (!this)
			return false;
		const auto Valid = *reinterpret_cast<uintptr_t*>((uintptr_t)mem::game_assembly_base + CO::IsValidChildType); //internal virtual bool IsValidChildType(XmlNodeType type) { }
		return Valid;
	}
	 
	bool IsNpc() {
		DWORD64 PlayerModel = mem::read<uintptr_t>((uintptr_t)this + O::BasePlayer::playerModel); //	public PlayerModel playerModel;
		return mem::read<bool>(PlayerModel + O::PlayerModel::IsNpck__BackingField);//private bool <IsNpc>k__BackingField;
	}

	DWORD64 GetSteamID() {
		return safe_read(this + O::BasePlayer::userID, DWORD64);
	}

	bool IsDead() {
		if (!this) return true;
		return mem::read<bool>((uintptr_t)this + O::BaseCombatEntity::lifestate);
	}

	float GetHealth() {
		return mem::read<float>((uintptr_t)this + _health);
	}
	rust::list<weapon*>* get_belt_items()
	{
		const auto     inventory = *reinterpret_cast<uintptr_t*>((uintptr_t)this + player_inventory);
		if (!inventory)
			return {};

		const auto container_belt = *reinterpret_cast<uintptr_t*>(inventory + containerBelt);
		if (!container_belt)
			return {};


		const auto list_wrapper = *reinterpret_cast<uintptr_t*>(container_belt + itemList);
		if (!list_wrapper)
			return {};

		const auto item_list =
			*reinterpret_cast<rust::list<weapon*>**>(list_wrapper + 0x10);
		if (!item_list)
			return {};

		return item_list;
	}
	rust::list<weapon*>* get_wearable_items()
	{
		const auto     inventory = *reinterpret_cast<uintptr_t*>((uintptr_t)this + player_inventory);
		if (!inventory)
			return {};

		const auto container_belt = *reinterpret_cast<uintptr_t*>(inventory + containerWear);
		if (!container_belt)
			return {};


		const auto list_wrapper = *reinterpret_cast<uintptr_t*>(container_belt + itemList);
		if (!list_wrapper)
			return {};

		const auto item_list =
			*reinterpret_cast<rust::list<weapon*>**>(list_wrapper + 0x10);
		if (!item_list)
			return {};

		return item_list;
	}
	bool HasFlags(int Flg) {
		return (mem::read<int>((uintptr_t)this + playerFlags) & Flg);
	}

	PlayerEyes* Radar_eyes() { return mem::read<PlayerEyes*>((uintptr_t)this + O::BasePlayer::eyes); }

	float GetJumpHeight_()
	{
		return GetJumpHeight(this);
	}

	PlayerTick* lastSentTick() {
		return (PlayerTick*)mem::read<DWORD64*>((uintptr_t)this + O::BasePlayer::lastSentTick);
	}

	Player_Model* get_player_model2() {
		return (Player_Model*)mem::read<DWORD64*>((uintptr_t)this + playerModel);
	}

	float GetHeight(bool ducked)
	{
		if (ducked)
		{
			return 1.1f;
		}
		return 1.8f;
	}

	bool Has_modelstate_flags(int Flg) {
		DWORD64 mstate = mem::read<DWORD64>((uintptr_t)this + modelState);

		return (mem::read<int>(mstate + 0x24) & Flg);
	}

	float GetHeight()
	{
		return this->GetHeight(this->Has_modelstate_flags(1));
	}

	float GetRadius()
	{
		return 0.5f;
	}

	float Time() {
		return safe_read(this + O::BasePlayer::lastSentTickTime, float);
	}

	Vector GetBoneByID(BoneList BoneID) {
		return GetPosition(GetTransform(BoneID));
	}






	void SpiderMan() {
		*reinterpret_cast<float*>(this + 0xb0) = 0.f;
	}
	void Giraffe() {
		if (vars::misc::eyeoffset && unity::GetKey(rust::classes::KeyCode::Y)) {
			auto playereye = *reinterpret_cast<uintptr_t*>((uintptr_t)this + eyes);
			mem::write<Vector>(playereye + 0x38, Vector(0, 1.3f, 0));
		}

	}

	void Admintime() {
		auto MrYasin = *reinterpret_cast<uintptr_t*>((uintptr_t)mem::game_assembly_base + CO::ConVar_Admin_c); //"Name": "ConVar.Admin_TypeInfo", "Signature": "ConVar_Admin_c*"
		auto Kors = *reinterpret_cast<uintptr_t*>((uintptr_t)MrYasin + 0xB8);
		mem::write<float>(Kors + 0x0, vars::visuals::DayTime);
	}
	/*void debugcamera()
	{
		createprefab(L"assets/bundled/prefabs/system/debug/debug_camera.prefab", vector3(0, 0, 0), Quaternion());
	}*/
	void todsky() {
		UINT64 klass = safe_read(mem::game_assembly_base + CO::TOD_Sky_TypeInfo, UINT64);// "Name": "TOD_Sky_TypeInfo",
		UINT64 static_fields = safe_read(klass + 0xB8, UINT64);
		UINT64 instances = safe_read(static_fields, UINT64);
		UINT64 List = safe_read(instances + 0x10, UINT64);
		UINT64 TOD_Sky = safe_read(List + 0x20, UINT64);
		const auto TOD_CycleParameters = mem::read<uintptr_t>(TOD_Sky + 0x38);
		UINT64 night = safe_read(TOD_Sky + 0x58, UINT64);
		UINT64 day = safe_read(TOD_Sky + 0x50, UINT64);
		UINT64 stars = safe_read(TOD_Sky + 0x70, UINT64);
		UINT64 ambient = safe_read(TOD_Sky + 0x90, UINT64);
		if (vars::misc::todsky) {
			safe_write(night + 0x50, 15.f, float);
			safe_write(day + 0x50, 2.f, float);
			safe_write(stars + 0x14, vars::misc::staramount, float);
		}
	}

	float MaxVelocity() {
		if (!this) return 0.f;

		float s = get_maxspeed(this);
		auto m = get_mountable();
		if (m)
			return s * 4;
		return s;
	}
	float boundspadding() {
		if (!this) return 0;
		return BoundsPadding(this);
	}
	void send_client_tick() {
		if (!this) return;
		return SendClientTick(this);
	}
 

		void fov() {
		
			
			 
			
		bool zooming = false;
		if (vars::misc::zoomtoggle && unity::GetKey(rust::classes::KeyCode::Z)) {
			zooming = true;
		}
		else {
			zooming = false;
		}
		if (zooming) {
			auto convar = *reinterpret_cast<uintptr_t*>((uintptr_t)mem::game_assembly_base + CO::ConVar_Graphics_c); //"ConVar_Graphics_c*"
			auto unknown = *reinterpret_cast<uintptr_t*>((uintptr_t)convar + 0xb8);
			*reinterpret_cast<float*>(unknown + 0x18) = 30.f;
		}
		if (!zooming) {
			auto convar = *reinterpret_cast<uintptr_t*>((uintptr_t)mem::game_assembly_base + CO::ConVar_Graphics_c); //"ConVar_Graphics_c*"
			auto unknown = *reinterpret_cast<uintptr_t*>((uintptr_t)convar + 0xb8);
			*reinterpret_cast<float*>(unknown + 0x18) = vars::misc::playerfov;
		}
	}

	basemountable* get_mountable() {
		return mem::read<basemountable*>((uintptr_t)this + mounted);
	}

	wchar_t* get_player_name() {
		auto player_name = (str)(*reinterpret_cast<uintptr_t*>((uintptr_t)this + _displayName));
		return player_name->str;
	}
	aim_target get_aimbot_target(Vector source, float max_distance = 500) {
		aim_target best_target = aim_target();

		if (!cliententities) {
			cliententities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
			if (!cliententities)
				return best_target;
		}

		rust::classes::list* entity_list = (rust::classes::list*)cliententities;

		auto list_value = entity_list->get_value<uintptr_t>();
		if (!list_value)
			return best_target;

		auto size = entity_list->get_size();
		if (!size)
			return best_target;

		auto buffer = entity_list->get_buffer<uintptr_t>();
		if (!buffer)
			return best_target;

		for (int i = 0; i <= size; i++) {
			auto current_object = *reinterpret_cast<uintptr_t*>(buffer + 0x20 + (i * 0x8));
			if (!current_object)
				continue;

			auto base_object = *reinterpret_cast<uintptr_t*>(current_object + 0x10);
			if (!base_object)
				continue;

			auto object = *reinterpret_cast<uintptr_t*>(base_object + 0x30);
			if (!object)
				continue;

			WORD tag = *reinterpret_cast<WORD*>(object + 0x54);

			auto ent = *reinterpret_cast<uintptr_t*>(base_object + 0x28);

			auto ent_class = *reinterpret_cast<uintptr_t*>(ent);
			auto entity_class_name = (char*)*reinterpret_cast<uintptr_t*>(ent_class + 0x10);

			bool is_heli = false;

			if (*(int*)(entity_class_name + 4) == 'ileH')
				is_heli = true;

			if (tag == 6 && !vars::visuals::woundedflag)
				continue;

			if (is_heli && !vars::visuals::heli_esp)
				continue;

			if (tag != 6 && !is_heli)// not a player
				continue;

			auto player = (BasePlayer*)current_object;
			if (!player)
				continue;

			uintptr_t object_name_ptr = *reinterpret_cast<uintptr_t*>(object + 0x60);

			rust::classes::string object_name = *reinterpret_cast<rust::classes::string*>(object_name_ptr);

			if (m_strstr(object_name.zpad, _("LocalPlayer")))
				continue;

			aim_target target;
			target.player = player;

			if (!is_heli) {
				if (!player->is_alive())
					continue;

				if (player->is_sleeping()) {
					target.sleeping = true;
					continue;
				}

				if (player->is_teammate(this)) {
					target.teammate = true;
				}

				if (get_IsNpc(player->get_player_model())) {
					if (!vars::visuals::npc_esp)
						continue;
				}

				auto velocity = player->get_new_velocity();
				target.velocity = velocity;
			}
			else {
				auto velocity = GetWorldVelocity(player);
				target.velocity = velocity;
			}

			auto pos = is_heli ? player->get_bone_transform(19)->get_bone_position() : player->get_bone_transform((int)rust::classes::Bone_List::head)->get_bone_position();
			target.pos = pos;

			target.is_heli = is_heli;

			auto networkable = target.player->get_networkable();
			if (!networkable)
				continue;

			auto id = networkable->get_id();
			if (!id)
				continue;

			target.network_id = id;
			Vector lphead;
			lphead = local_player->get_bone_transform(48)->get_bone_position();
			float distancetp = lphead.get_3d_dist(player->get_bone_transform(19)->get_bone_position());

			auto visible = player->is_visible(source, pos);
			target.visible = visible;

			auto distance = source.get_3d_dist(pos);
			target.distance = distance;
			if (distance > max_distance)
				continue;

			auto fov = unity::get_fov(pos);
			target.fov = fov;
			//if (fov >= 100)//>= max fov
			//	continue;

			if (target < best_target)
				best_target = target;
		}
		return best_target;
	}
 
	uintptr_t get_weakspots() {
		return *reinterpret_cast<uintptr_t*>(this + weakspots);
	}


	Vector get_new_velocity() {
		auto player_model = *reinterpret_cast<uintptr_t*>((uintptr_t)this + playerModel);
		return *reinterpret_cast<Vector*>(player_model + newVelocity);
	}

	modelstate* get_model_state() {
		return *reinterpret_cast<modelstate**>((uintptr_t)this + modelState);
	}
	void set_client_tick_interval(float tick) {
		if (!this)
			return;

		*reinterpret_cast<float*>((uintptr_t)this + clientTickInterval) = tick;
	}
 

	void set_admin_flag(rust::classes::PlayerFlags flag) {
		int PlayerFlag = *reinterpret_cast<int*>((uintptr_t)this + playerFlags);

		*reinterpret_cast<int*>((uintptr_t)this + playerFlags) = PlayerFlag |= (int)flag;
	}

	unsigned long get_steam_id() {
		if (!this)
			return 0;

		if (!get_player_model())
			return 0;

		return *reinterpret_cast<unsigned long*>((uintptr_t)this + userID);
	}
	//bool isSameTeam(std::unique_ptr<BaseEntity>& localPlayer) {
	//	auto localTeam = kernelHandler.readmem<uint32_t>(localPlayer->player + 0x5D8); //public ulong currentTeam; 
	//	auto playerTeam = kernelHandler.readmem<uint32_t>(this->player + 0x5D8);

	//	if (localTeam == 0 || playerTeam == 0)
	//		return false;

	//	return (localTeam == playerTeam);
	//}
	bool is_teammate(BasePlayer* BasePlayer) {
    
        auto TeamId = (int)(BasePlayer + 0x5D8);
        auto LocalTeamId = (int)(this + 0x5D8);

        if (LocalTeamId == 0) return false;
        if (TeamId == LocalTeamId) return true;

        return false;
    }

	auto get_last_sent_ticket_time() {
		return *reinterpret_cast<float*>((uintptr_t)this + lastSentTickTime);
	}

	float lastSentTickTime_() {
		return *reinterpret_cast<float*>((DWORD64)this + O::BasePlayer::lastSentTickTime);
	}

	transform* get_bone_transform(int bone_id) {
		uintptr_t entity_model = *reinterpret_cast<uintptr_t*>((uintptr_t)this + O::BaseEntity::model); //public Model model;
		uintptr_t bone_dict = *reinterpret_cast<uintptr_t*>(entity_model + O::Model::boneTransforms);
		transform* BoneValue = *reinterpret_cast<transform**>(bone_dict + 0x20 + bone_id * 0x8);

		return BoneValue;
	}

	Vector Position()
	{
		return GetPosition(GetTransform(15)).midPoint(GetPosition(GetTransform(3)));
	}

	DWORD64 GetTransform(int bone)
	{
		uintptr_t player_model = mem::read<uintptr_t>((uintptr_t)this + O::BaseEntity::model);// public Model model;_public class BaseEntity : BaseNetworkable, IProvider, ILerpTarget, IPrefabPreProcess // TypeDefIndex: 8714
		uintptr_t boneTransforms = mem::read<uintptr_t>(player_model + O::Model::boneTransforms);//public Transform[] boneTransforms;
		uintptr_t BoneValue = mem::read<uintptr_t>((boneTransforms + (0x20 + (bone * 0x8))));
		return BoneValue;
	}

	typedef Vector(__stdcall* Transform)(UINT64);
	Vector GetPosition(ULONG_PTR pTransform)
	{
		if (!pTransform) return Vector();
		Transform original = (Transform)(mem::game_assembly_base + O::UnityEngine_Transform::get_position);
		Vector res = original(pTransform);
		return res;
	}

	bool is_visible(Vector source, Vector destination) {
		auto visible = unity::is_visible(source, destination);
		if (visible)
			return true;

		return false;
	}

	bool is_sleeping()
	{
		auto Flags = *reinterpret_cast<int*>((uintptr_t)this + playerFlags);
		return Flags & 16;
	}

	playereyes* get_player_eyes() {
		return *reinterpret_cast<playereyes**>((uintptr_t)this + eyes);
	}

	Vector GetVelocity()
	{
		const auto PlayerModel = mem::read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + playerModel);
		return mem::read<Vector>(PlayerModel + O::PlayerModel::newVelocity);
	}

	vector2 GetRA()
	{
		const auto Input = mem::read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + O::BasePlayer::input);
		return mem::read<vector2>(Input + O::PlayerInput::recoilAngles);//public Vector recoilAngles;
	}

	vector2 GetVA()
	{
		const auto Input = mem::read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + O::BasePlayer::input);
		return mem::read<vector2>(Input + O::PlayerInput::bodyAngles);
	}

	void SetVA(const vector2& VA)
	{
		const auto Input = mem::read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + O::BasePlayer::input);
		mem::write<vector2>(Input + O::PlayerInput::bodyAngles, VA);
	}

	weapon* get_active_weapon() {
		unsigned int ActUID = mem::read<unsigned int>((uintptr_t)this + clActiveItem);
		if (!ActUID) return 0;
		weapon* ActWeapon;
		uint64_t Inventory = mem::read<uint64_t>((uintptr_t)this + player_inventory);
		uint64_t Belt = mem::read<uint64_t>(Inventory + 0x28);
		uint64_t ItemList = mem::read<uint64_t>(Belt + 0x40);
		auto items = mem::read<uint64_t>(ItemList + 0x10);
		if (!items) return 0;
		for (int i = 0; i < 6; i++) //For each slot	
		{
			weapon* WeaponInfo = mem::read<weapon*>(items + 0x20 + (i * 0x8));

			unsigned int WeaponUID = mem::read<unsigned int>((uintptr_t)WeaponInfo + 0x20);
			if (!WeaponUID)
				return 0;
			if (ActUID == WeaponUID)
			{
				ActWeapon = WeaponInfo;
				return ActWeapon;
			}
		}
		return 0;
	}
	uintptr_t get_player_model() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + playerModel);
	}
	uintptr_t get_model() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + model);
	}
	networkable* get_networkable() {
		return *reinterpret_cast<networkable**>((uintptr_t)this + net);
	}
	playerwalkmovement* get_movement() {
		return *reinterpret_cast<playerwalkmovement**>((uintptr_t)this + movement);
	}
	playerwalkmovement* get_movement2() {
		return *reinterpret_cast<playerwalkmovement**>((uintptr_t)this + O::BasePlayer::movement);
	}
	float get_health() {
		return *reinterpret_cast<float*>((uintptr_t)this + _health);
	}
	float get_max_health() {
		return *reinterpret_cast<float*>((uintptr_t)this + _maxHealth);
	}
	bool is_local_player() {
		if (!this) return false;
		auto player_model = get_player_model();
		if (!player_model) return false;
		auto is_local = *reinterpret_cast<bool*>(player_model + isLocalPlayer);
		return is_local;
	}
	bool is_alive() {
		if (!this) return 0;
		const auto life_state = *reinterpret_cast<uint32_t*>((uintptr_t)this + lifestate);
		return life_state == 0;
	}
	rust::classes::game_object* get_game_object() {
		if (!(uintptr_t)this) return nullptr;
		const auto unk0 = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
		if (!unk0) return nullptr;
		const auto unk1 = *reinterpret_cast<rust::classes::game_object**>(unk0 + 0x30);
		if (!unk1) return nullptr;
		return unk1;
	}
};

class HeldEntity : public BaseEntity {

};



Vector WorldToScreen(Vector position)
{
	auto matrix = unity::get_view_matrix();

	if (!matrix.m) {
		return { 0,0,0 };
	}
	Vector out;
	const auto temp = matrix.transpose();

	auto translation_vector = Vector{ temp[3][0], temp[3][1], temp[3][2] };
	auto up = Vector{ temp[1][0], temp[1][1], temp[1][2] };
	auto right = Vector{ temp[0][0], temp[0][1], temp[0][2] };

	float w = translation_vector.Dot(position) + temp[3][3];

	if (w < 0.098f) {
		return Vector(0, 0, 0);
	}

	float x = up.Dot(position) + temp._24;
	float y = right.Dot(position) + temp._14;

	out.x = (static_cast<float>(unity::get_width()) / 2) * (1 + y / w);
	out.y = (static_cast<float>(unity::get_height()) / 2) * (1 - x / w);
	out.z = w;

	return out;
}

namespace utils {
	Vector GetEntityPosition(uint64_t entity) {
		if (!entity) return Vector::Zero();

		uintptr_t plyVis = safe_read(entity + 0x8, uintptr_t);
		if (!plyVis) return Vector::Zero();

		uintptr_t visualState = safe_read(plyVis + 0x38, uintptr_t);
		if (!visualState) return Vector::Zero();

		Vector ret = safe_read(visualState + 0x90, Vector);
		return ret;
	}
	Vector ClosestPoint(BasePlayer* player, Vector vec) {
		typedef Vector(__stdcall* CPoint)(BasePlayer*, Vector);
		Vector result = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(player, vec);
		return result;
	}
	bool LineOfSight(Vector a, Vector b) {
		typedef bool(__stdcall* LOS)(Vector, Vector, int, float);
		bool result = ((LOS)(mem::game_assembly_base + CO::LineOfSight))(a, b, 2162688 | 8388608 | 2097152, 0.f); // public static bool LineOfSight(Vector3 p0, Vector3 p1, int layerMask, BaseEntity ignoreEntity) { }
		return result;
	}
};
class AimResult {
public:
	bool valid;
	BasePlayer* entity;
	Vector pos;
	float dist = 10000.f;
	float realdist = 0.f;
	float fov = 10000.f;
	bool operator<(const AimResult& b) { return this->dist < b.dist; }
	bool operator>(const AimResult& b) { return this->dist > b.dist; }
	bool operator<=(const AimResult& b) { return this->dist <= b.dist; }
	bool operator>=(const AimResult& b) { return this->dist >= b.dist; }
	AimResult() {
		this->valid = false;
	}
	AimResult(Vector target) {
		this->valid = false;
		this->pos = target;
	}
	/*static AimResult get_closest_object(Vector from, const char* namee, Vector ignore = Vector::Zero(), Vector ignore2 = Vector::Zero(), Vector ignore3 = Vector::Zero(), bool classname = false, const char* classnamee = _(""), float get_dist = 99999.f, bool vis = false, bool y = false) {
		AimResult lowest = AimResult();
		uintptr_t ClientEntities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
		uintptr_t ClientEntities_list = *reinterpret_cast<uintptr_t*>(ClientEntities + 0x10);
		uintptr_t ClientEntities_values = *reinterpret_cast<uintptr_t*>(ClientEntities_list + 0x28);
		int EntityCount = *reinterpret_cast<int*>(ClientEntities_values + 0x10);
		uintptr_t EntityBuffer = *reinterpret_cast<uintptr_t*>(ClientEntities_values + 0x18);
		for (int i = 0; i <= EntityCount; i++) {
			uintptr_t Entity = *reinterpret_cast<uintptr_t*>(EntityBuffer + 0x20 + (i * 0x8));
			if (Entity <= 100000) continue;
			uintptr_t Object = *reinterpret_cast<uintptr_t*>(Entity + 0x10);
			if (Object <= 100000) continue;
			uintptr_t ObjectClass = *reinterpret_cast<uintptr_t*>(Object + 0x30);
			if (ObjectClass <= 100000) continue;
			pUncStr name = *reinterpret_cast<pUncStr*>(ObjectClass + 0x60);
			if (!name) continue;
			char* buff = name->stub;
			AimResult res = AimResult();
			if (classname) {
				if (m_strstr((char*)safe_read(safe_read(safe_read(Object + 0x28, DWORD64), DWORD64) + 0x10, DWORD64), classnamee)) {
					uintptr_t a = safe_read(ObjectClass + 0x30, UINT64);
					float dist = Distance3D(utils::GetEntityPosition(a), from);
					if (utils::GetEntityPosition(a) != ignore && utils::GetEntityPosition(a) != ignore2 && utils::GetEntityPosition(a) != ignore3) {
						res.valid = dist <= get_dist;
						res.dist = dist;
						res.entity = (BasePlayer*)Entity;
						res.pos = utils::GetEntityPosition(a);
						if (res < lowest) lowest = res;
					}
				}
			}
			else {
				if (m_strstr(buff, namee)) {
					uintptr_t a = safe_read(ObjectClass + 0x30, UINT64);
					float dist = Distance3D(utils::GetEntityPosition(a), from);
					if (utils::GetEntityPosition(a) != ignore && utils::GetEntityPosition(a) != ignore2 && utils::GetEntityPosition(a) != ignore3) {
						if (vis ? utils::LineOfSight(utils::GetEntityPosition(a), from) : true) {
							if (y) {
								if (utils::GetEntityPosition(a).y > 0) {
									res.valid = dist <= get_dist;
									res.dist = dist;
									res.entity = (BasePlayer*)Entity;
									res.pos = utils::GetEntityPosition(a);
									if (res < lowest) lowest = res;
								}
							}
							else {
								res.valid = dist <= get_dist;
								res.dist = dist;
								res.entity = (BasePlayer*)Entity;
								res.pos = utils::GetEntityPosition(a);
								if (res < lowest) lowest = res;
							}
						}
					}
				}

			}
		}
		return lowest;
	}*/
};
struct Ray_2 {
	Vector origin;
	Vector dir;
	Ray_2(Vector o, Vector d) {
		origin = o;
		dir = d;
	}
	Ray_2() {}
};

DWORD64 hkMelee = 0;
void DoMeleeAttack(AimResult target, DWORD64 active, bool transform = true) {
	if (!target.valid || !active) return;
	Vector lp = local_player->Position();
	typedef float(__stdcall* A)();
	float time = ((A)(mem::game_assembly_base + O::UnityEngine_Time::get_time))();
	if (safe_read(active + O::AttackEntity::nextAttackTime, float) >= time) { //nextattacktime
		return;
	}
	if (safe_read(active + O::AttackEntity::timeSinceDeploy, float) < safe_read(active + O::AttackEntity::deployDelay, float)) {
		return;
	}
	//HitTest
	auto hit_test_class = il2cpp::init_class(_("HitTest"));
	if (!hit_test_class) return;
	typedef DWORD64(__stdcall* NNew)(DWORD64);
	auto HitTest = ((NNew)il2cpp::methods::object_new(hit_test_class));
	Ray_2 ray = Ray_2(lp, (target.pos - lp).Normalize());
	safe_write(HitTest + O::HitTest::MaxDistance, 1000.f, float); //MaxDistance
	DWORD64 trans;
	if (transform) {
		trans = target.entity->GetTransform(BoneList::neck);
	}
	else {
		typedef DWORD64(__stdcall* GetTr)(DWORD64);
		trans = ((GetTr)(mem::game_assembly_base + O::UnityEngine_Component::get_transform))((DWORD64)target.entity);
	}
	if (!trans) return;
	safe_write(HitTest + O::HitTest::HitTransform, trans, DWORD64); //HitTransform
	safe_write(HitTest + O::HitTest::AttackRay, ray, Ray_2);
	safe_write(HitTest + O::HitTest::DidHit, true, bool); //DidHit
	safe_write(HitTest + O::HitTest::HitEntity, target.entity, BasePlayer*); //HitEntity
	typedef Vector(__stdcall* ITP)(DWORD64, Vector);
	Vector hitpoint = ((ITP)(mem::game_assembly_base + O::UnityEngine_Transform::InverseTransformPoint))(trans, target.pos);
	safe_write(HitTest + O::HitTest::HitPoint, hitpoint, Vector); //HitPoint
	safe_write(HitTest + O::HitTest::HitNormal, Vector(0, 0, 0), Vector); //HitNormal
	safe_write(HitTest + O::HitTest::damageProperties, safe_read(active + O::BaseMelee::damageProperties, DWORD64), DWORD64);
	typedef void(__stdcall* Atk)(DWORD64, DWORD64);
	float kd = safe_read(active + O::AttackEntity::repeatDelay, float);
	typedef void(__stdcall* StartKD)(DWORD64, float);
	((StartKD)(mem::game_assembly_base + O::AttackEntity::StartAttackCooldown))(active, kd);
	return ((Atk)(mem::game_assembly_base + O::BaseMelee::ProcessAttack))(active, (DWORD64)HitTest);
}


float MaxMeleeDist(DWORD64 melee, bool hren) {
	float pad = 0.1f;
	typedef float(__stdcall* RetF)();
	float time = ((RetF)(mem::game_assembly_base + O::UnityEngine_Time::get_time))();
	float desyncTime = max(time - local_player->Time() - 0.0325f, 0.f);
	float res = pad + desyncTime * 5.5f;
	if (hren) {
		res += (1.5f * safe_read(melee + 0x290, float)); //maxDistance
	}
	return max(res, 0.05f);
}
AimResult TargetMeleeTest(BasePlayer* Player, DWORD64 melee) {
	AimResult res = AimResult();
	if (!Player || !Player->IsValid()) return res;
	typedef Vector(__stdcall* CPoint)(BasePlayer*, Vector);
	Vector prepos = Player->Position();
	Vector closest_entity = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(local_player, prepos);
	Vector closest_local = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(Player, closest_entity);
	float disttoentity = MaxMeleeDist(melee, false);
	float distfromlocal = MaxMeleeDist(melee, true);
	float maxdist = distfromlocal + disttoentity;
	float realdist = (closest_local - closest_entity).Length();
	if (realdist > maxdist) return res;

	Vector target;
	if (realdist <= disttoentity) {
		target = closest_entity;
	}
	else {
		Vector dir = (closest_entity - closest_local).Normalize();
		target = closest_local + dir * disttoentity;
	}
	res.valid = utils::LineOfSight(closest_local, target);
	if (!res.valid) return res;
	Vector lppos = local_player->Position();
	res.valid = utils::LineOfSight(lppos, target);
	if (!res.valid) return res;
	res.dist = realdist;
	res.entity = Player;
	res.pos = target;
	return res;
}
