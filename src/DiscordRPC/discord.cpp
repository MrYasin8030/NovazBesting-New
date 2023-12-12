#include "Discord.h"
#include "disrpc/Includes/discord_rpc.h"
#include <time.h>

void Discord::Initialize()
{
    DiscordEventHandlers Handle;
    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize("1043238570611187762", &Handle, 1, NULL);
}
void Discord::Update()
{
    DiscordRichPresence discord;
    memset(&discord, 0, sizeof(discord));
    discord.details = "Playing Rust";
    discord.state = "Build: Beta";
    discord.startTimestamp = time(0);
    discord.largeImageKey = "infinity";
    discord.smallImageKey = "rust_icon";//infinity
    Discord_UpdatePresence(&discord);
}