#pragma once
/*

namespace O {
	namespace BasePlayer {
		constexpr auto playerModel = 0x678; // public PlayerModel playerModel; 
		constexpr auto movement = 0x6A0; // 	public BaseMovement movement;
		constexpr auto lastSentTickTime = 0x894; // private float lastSentTickTime; 
		constexpr auto input = 0x698; // public PlayerInput input; 
		constexpr auto eyes = 0x8D0; // 	public PlayerEyes eyes; 
		constexpr auto lastSentTick = 0x8A0; // private PlayerTick lastSentTick;
		constexpr auto userID = 0x910; // public ulong userID;
	};

	namespace BaseMovement {
		constexpr auto Groundedk__BackingField = 0x4C; // private float <Grounded>k__BackingField;
		constexpr auto TargetMovementk__BackingField = 0x34; //private Vector3 <TargetMovement>k__BackingField;
	};

	namespace BaseProjectile {
		constexpr auto reloadTime = 0x2B8; // public float reloadTime;
		constexpr auto LaunchProjectile = 0x5EA690; // public virtual void LaunchProjectile() { }

	};

	namespace PlayerWalkMovement {
		constexpr auto groundAngleNew = 0xC8; // private float groundAngleNew;
		constexpr auto groundAngle = 0xC4;	// private float groundAngle;
	};


	namespace AttackEntity {
		constexpr auto nextAttackTime = 0x250; // private float nextAttackTime;
		constexpr auto deployDelay = 0x1F8; // public float deployDelay;
		constexpr auto repeatDelay = 0x1FC; // public float repeatDelay;
		constexpr auto timeSinceDeploy = 0x25C; // private float timeSinceDeploy;

		constexpr auto StartAttackCooldown = 0x7C4CE0; // protected void StartAttackCooldown(float cooldown) { }

	};

	namespace BaseEntity {
		constexpr auto model = 0xB8; // public Model model; | public class BaseEntity : BaseNetworkable, IProvider, IPosLerpTarget, ILerpInfo, IPrefabPreProcess

		constexpr auto ClosestPoint = 0x5BC8B0; // public Vector3 ClosestPoint(Vector3 position) { } | public class BaseEntity : BaseNetworkable, IProvider, IPosLerpTarget, ILerpInfo, IPrefabPreProcess
		constexpr auto SendSignalBroadcast = 0x5C6D60;//public void SendSignalBroadcast(BaseEntity.Signal signal, string arg = "") { }

	};

	namespace UnityEngine_Time {

		constexpr auto get_time = 0x2924980; // public static float get_time() { }

	};

	namespace UnityEngine_Component {

		constexpr auto get_transform = 0x28F9550; // public Transform get_transform() { } | public class Component : Object 

	};

	namespace UnityEngine_Transform {

		constexpr auto get_position = 0x2927E90; // public Vector3 get_position() { } | public class Transform : Component, IEnumerable
		constexpr auto InverseTransformPoint = 0x2926110; // public Vector3 InverseTransformPoint(Vector3 position) { }
	};

	namespace HitTest {
		constexpr auto HitTransform = 0xB0; // public Transform HitTransform;
		constexpr auto MaxDistance = 0x34; // public float maxDistance; | public class PlayerNameTag : MonoBehaviour
		constexpr auto AttackRay = 0x14; // public Ray AttackRay;
		constexpr auto DidHit = 0x66; // public bool DidHit;
		constexpr auto HitEntity = 0x88; // public BaseEntity HitEntity;
		constexpr auto HitPoint = 0x90; // public Vector3 HitPoint;
		constexpr auto HitNormal = 0x9c; // public Vector3 HitNormal;
		constexpr auto damageProperties = 0x68; // public DamageProperties damageProperties;

	};
	namespace System_Math {

		constexpr auto Sqrt = 0x1E75C20; // public static double Sqrt(double d) { }
		constexpr auto Asin = 0x1E74FF0; // public static double Asin(double d) { }
		constexpr auto Atan2 = 0x1E75000; // public static double Atan2(double y, double x) { }
		constexpr auto Sin = 0x1E75C00; // public static double Sin(double a) { }
		constexpr auto Cos = 0x1E750D0; // public static double Cos(double d) { }
		constexpr auto Abs = 0x1E74F70; // public static int Abs(int value) { } | public static class Math 

	};
	namespace PlayerEyes {
		constexpr auto get_rotation = 0x8154F0; // public Quaternion get_rotation() { } | public class PlayerEyes : EntityComponent<BasePlayer>
		constexpr auto get_center = 0x814A40; // public Vector3 get_center() { } | public class PlayerEyes : EntityComponent<BasePlayer>

	};
	namespace BaseMelee {
		constexpr auto damageProperties = 0x280; // public DamageProperties damageProperties;

		constexpr auto ProcessAttack = 0x5E22E0; // protected virtual void ProcessAttack(HitTest hit) { }

	};

	namespace PlayerInput {
		constexpr auto bodyAngles = 0x3C; // private Vector3 bodyAngles;
		constexpr auto recoilAngles = 0x64; // public Vector3 recoilAngles;

	};

	namespace PlayerModel {
		constexpr auto position = 0x1B8; // internal Vector3 position; | public class PlayerModel : ListComponent<PlayerModel>, IOnParentDestroying 
		constexpr auto IsNpck__BackingField = 0x2C8; // private bool <IsNpc>k__BackingField; | public class PlayerModel : ListComponent<PlayerModel>, IOnParentDestroying
		constexpr auto newVelocity = 0x1DC; // private Vector3 newVelocity;
		constexpr auto _multiMesh = 0x270; // private SkinnedMultiMesh _multiMesh;

	};

	namespace Item {
		constexpr auto heldEntity = 0xB0; // private EntityRef heldEntity;

	};

	namespace Model {
		constexpr auto boneTransforms = 0x48; // public Transform[] boneTransforms; | public class Model : MonoBehaviour, IPrefabPreProcess

	};

	namespace BaseCombatEntity {
		constexpr auto lifestate = 0x254; // public BaseCombatEntity.LifeState lifestate;

	};

}

namespace CO {
	constexpr auto ConVar_Admin_c = 54580088; // ConVar_Admin_c
	constexpr auto ConVar_Graphics_c = 54875864; // ConVar_Graphics_c
	constexpr auto TOD_Sky_TypeInfo = 54842288; // TOD_Sky_TypeInfo
	constexpr auto ProjectileShoot = 54866584; // Method$BaseEntity.ServerRPC\u003CProjectileShoot\u003E() =// Method$BaseEntity.ServerRPC<ProjectileShoot>()
	constexpr auto Method$BaseEntity_ServerRPC_PlayerProjectileAttack___ = 54865920; // Method$BaseEntity.ServerRPC<PlayerProjectileAttack>()
	constexpr auto Method$BaseEntity_ServerRPC_uint = 54867240; // Method$BaseEntity.ServerRPC<uint>()

	constexpr auto ServerRPC = 0x5C6F10; // public void ServerRPC(string funcName) { }
	constexpr auto LineOfSight = 0x7977F0; // public static bool LineOfSight(Vector3 p0, Vector3 p1, int layerMask, BaseEntity ignoreEntity) { }
	constexpr auto IsValidChildType = 0x4DC300; // internal virtual bool IsValidChildType(XmlNodeType type) { }
	constexpr auto IsFullyHacked = 0x4E2A80; // public bool IsFullyHacked() { }
	constexpr auto IsHidden = 0x4E46E0; // public bool IsHidden() { }
	constexpr auto set_rayleigh = 0xC506D0;// public static void set_atmosphere_rayleigh(float value) { }
	constexpr auto set_mie = 0xC50620; // public static void set_atmosphere_mie(float value) { }
	constexpr auto set_brightness = 0xC50410; // public static void set_atmosphere_brightness(float value) { }
}



*/







/////STEAM RUST BY MRYASÝN

namespace O {
	namespace BasePlayer {
		constexpr auto playerModel = 0x678; // public PlayerModel playerModel; 
		constexpr auto movement = 0x6A0; // 	public BaseMovement movement;
		constexpr auto lastSentTickTime = 0x894; // private float lastSentTickTime; 
		constexpr auto input = 0x698; // public PlayerInput input; 
		constexpr auto eyes = 0x8D0; // 	public PlayerEyes eyes; 
		constexpr auto lastSentTick = 0x8A0; // private PlayerTick lastSentTick;
		constexpr auto userID = 0x910; // public ulong userID;
	};

	namespace BaseMovement {
		constexpr auto Groundedk__BackingField = 0x4C; // private float <Grounded>k__BackingField;
		constexpr auto TargetMovementk__BackingField = 0x34; //private Vector3 <TargetMovement>k__BackingField;
	};

	namespace BaseProjectile {
		constexpr auto reloadTime = 0x2B8; // public float reloadTime;
		constexpr auto LaunchProjectile = 0x5B8E00; // public virtual void LaunchProjectile() { }

	};

	namespace PlayerWalkMovement {
		constexpr auto groundAngleNew = 0xC8; // private float groundAngleNew;
		constexpr auto groundAngle = 0xC4;	// private float groundAngle;
	};


	namespace AttackEntity {
		constexpr auto nextAttackTime = 0x250; // private float nextAttackTime;
		constexpr auto deployDelay = 0x1F8; // public float deployDelay;
		constexpr auto repeatDelay = 0x1FC; // public float repeatDelay;
		constexpr auto timeSinceDeploy = 0x25C; // private float timeSinceDeploy;

		constexpr auto StartAttackCooldown = 0x793490; // protected void StartAttackCooldown(float cooldown) { }

	};

	namespace BaseEntity {
		constexpr auto model = 0xB8; // public Model model; | public class BaseEntity : BaseNetworkable, IProvider, IPosLerpTarget, ILerpInfo, IPrefabPreProcess

		constexpr auto ClosestPoint = 0x58B020; // public Vector3 ClosestPoint(Vector3 position) { } | public class BaseEntity : BaseNetworkable, IProvider, IPosLerpTarget, ILerpInfo, IPrefabPreProcess
		constexpr auto SendSignalBroadcast = 0x5954D0;//public void SendSignalBroadcast(BaseEntity.Signal signal, string arg = "") { }

	};

	namespace UnityEngine_Time {

		constexpr auto get_time = 0x28D3B10; // public static float get_time() { }

	};

	namespace UnityEngine_Component {

		constexpr auto get_transform = 0x28A86E0; // public Transform get_transform() { } | public class Component : Object 

	};

	namespace UnityEngine_Transform {

		constexpr auto get_position = 0x28D7020; // public Vector3 get_position() { } | public class Transform : Component, IEnumerable
		constexpr auto InverseTransformPoint = 0x28D52A0; // public Vector3 InverseTransformPoint(Vector3 position) { }
	};

	namespace HitTest {
		constexpr auto HitTransform = 0xB0; // public Transform HitTransform;
		constexpr auto MaxDistance = 0x34; // public float maxDistance; | public class PlayerNameTag : MonoBehaviour
		constexpr auto AttackRay = 0x14; // public Ray AttackRay;
		constexpr auto DidHit = 0x66; // public bool DidHit;
		constexpr auto HitEntity = 0x88; // public BaseEntity HitEntity;
		constexpr auto HitPoint = 0x90; // public Vector3 HitPoint;
		constexpr auto HitNormal = 0x9c; // public Vector3 HitNormal;
		constexpr auto damageProperties = 0x68; // public DamageProperties damageProperties;

	};
	namespace System_Math {

		constexpr auto Sqrt = 0x1E24F20; // public static double Sqrt(double d) { }
		constexpr auto Asin = 0x1E242F0; // public static double Asin(double d) { }
		constexpr auto Atan2 = 0x1E24300; // public static double Atan2(double y, double x) { }
		constexpr auto Sin = 0x1E24F00; // public static double Sin(double a) { }
		constexpr auto Cos = 0x1E243D0; // public static double Cos(double d) { }
		constexpr auto Abs = 0x1E24270; // public static int Abs(int value) { } | public static class Math 

	};
	namespace PlayerEyes {
		constexpr auto get_rotation = 0x7E3CA0; // public Quaternion get_rotation() { } | public class PlayerEyes : EntityComponent<BasePlayer>
		constexpr auto get_center = 0x7E31F0; // public Vector3 get_center() { } | public class PlayerEyes : EntityComponent<BasePlayer>

	};
	namespace BaseMelee {
		constexpr auto damageProperties = 0x280; // public DamageProperties damageProperties;

		constexpr auto ProcessAttack = 0x5B0A50; // protected virtual void ProcessAttack(HitTest hit) { }

	};

	namespace PlayerInput {
		constexpr auto bodyAngles = 0x3C; // private Vector3 bodyAngles;
		constexpr auto recoilAngles = 0x64; // public Vector3 recoilAngles;

	};

	namespace PlayerModel {
		constexpr auto position = 0x1B8; // internal Vector3 position; | public class PlayerModel : ListComponent<PlayerModel>, IOnParentDestroying 
		constexpr auto IsNpck__BackingField = 0x2C8; // private bool <IsNpc>k__BackingField; | public class PlayerModel : ListComponent<PlayerModel>, IOnParentDestroying
		constexpr auto newVelocity = 0x1DC; // private Vector3 newVelocity;
		constexpr auto _multiMesh = 0x270; // private SkinnedMultiMesh _multiMesh;

	};

	namespace Item {
		constexpr auto heldEntity = 0xB0; // private EntityRef heldEntity;

	};

	namespace Model {
		constexpr auto boneTransforms = 0x48; // public Transform[] boneTransforms; | public class Model : MonoBehaviour, IPrefabPreProcess

	};

	namespace BaseCombatEntity {
		constexpr auto lifestate = 0x254; // public BaseCombatEntity.LifeState lifestate;

	};

}

namespace CO {
	constexpr auto ConVar_Admin_c = 54088184; // ConVar_Admin_c
	constexpr auto ConVar_Graphics_c = 54380448; // ConVar_Graphics_c
	constexpr auto TOD_Sky_TypeInfo = 54329896; // TOD_Sky_TypeInfo
	constexpr auto ProjectileShoot = 54293824; // Method$BaseEntity.ServerRPC\u003CProjectileShoot\u003E() =// Method$BaseEntity.ServerRPC<ProjectileShoot>()
	constexpr auto Method$BaseEntity_ServerRPC_PlayerProjectileAttack___ = 54293168; // Method$BaseEntity.ServerRPC<PlayerProjectileAttack>()
	constexpr auto Method$BaseEntity_ServerRPC_uint = 54294488; // Method$BaseEntity.ServerRPC<uint>()

	constexpr auto ServerRPC = 0x595680; // public void ServerRPC(string funcName) { }
	constexpr auto LineOfSight = 0x765F90; // public static bool LineOfSight(Vector3 p0, Vector3 p1, int layerMask, BaseEntity ignoreEntity) { }
	constexpr auto IsValidChildType = 0x4AAA70; // internal virtual bool IsValidChildType(XmlNodeType type) { }
	constexpr auto IsFullyHacked = 0x4B11F0; // public bool IsFullyHacked() { }
	constexpr auto IsHidden = 0x4B2E50; // public bool IsHidden() { }
	constexpr auto set_rayleigh = 0xC1EEA0;// public static void set_atmosphere_rayleigh(float value) { }
	constexpr auto set_mie = 0xC1EDF0; // public static void set_atmosphere_mie(float value) { }
	constexpr auto set_brightness = 0xC1EBE0; // public static void set_atmosphere_brightness(float value) { }
}
