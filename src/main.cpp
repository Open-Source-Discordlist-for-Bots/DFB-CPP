#include <string>
#include <sstream>
#include "cdltypes.hpp"
using namespace std;
using namespace CDL;
using timer = std::chrono::system_clock;
timer::time_point startup_time;


void echo(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    channel->send("Echo from "+msg->author->username+": "+args[0]);
}
void say(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    channel->send(args[0]);
     msg->remove();
}

void embedsay(CMessage msg, CChannel channel, CDL::cmdargs& args) {
     channel->send_embed({
             {"description", args[0]}
         });
     msg->remove();
     }



void invite(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    channel->send_embed({
        {"title", "Invite me"},
        {"description", extras::get_bot_invite_link()},
        {"color", 0xff0000},
    });
}

//FULL HELP COMMANDS

void help(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    if (args.empty()){

        channel->send_embed({
            {"title", "Commands for DFB"},
            {"description", "The Prefix is `dfb?`\n \n"
                            ":tools: **Servermanagment** \n"
                            "Moderate your server with various useful commands. \n \n "
                            ":gear:**Useful** \n"
                            "Useful functions that can help for your server \n \n"
                            "**Offical DFB.eu Server » [Invite](https://discord.gg/42vDtZxZSt)**"},
            {"color", 0x7289D9},
            {"footer", {{"text", "Use dfb?help {category} to see more commands"}, {"icon_url", extras::get_avatar_url(msg->author)}}},
            {"thumbnail", {{"url", extras::get_avatar_url(env.self)}}}
        });
    }
    else if (args[0] == "servermanagment"){
        channel->send_embed({
            {"title", "Commands for servermanagment"},
            {"description", "`dfb?approve {bot} {owner}` \n"
                            "Approves the metioned bot \n \n"
                            "`dfb?decline {bot} {owner} {PCKG_NAME} {reason}` \n"
                            "Declines the mntioned bots \n \n"
                            "`dfb?proc {bot} {owner}` \n"
                            "The mentioned bot is going into the certification process \n \n"
                            "`dfb?nproc {bot} {owner}` \n"
                            "The mentioned bot won't be certified! \n \n"
                            "`dfb?certified {owner} {bot}` \n "
                            "Certifies the mentioned bot \n \n"
                            "`dfb?warn {user} {reason}` \n"
                            "Warns a user. If they have 3 warns, the user will be banned. \n \n"
                            "`dfb?kick {user} {reason}` \n"
                            "Kicks a user \n \n"
                            "`dfb?ban {user} {reason}` \n"
                            "Banns a user \n \n"
                            "**Offical DFB.eu Server » [Invite](https://discord.gg/42vDtZxZSt)**"},
            {"color", 0x7289D9},
            {"footer", {{"text", "Use dfb?help {category} to see more commands"}, {"icon_url", extras::get_avatar_url(msg->author)}}},
            {"thumbnail", {{"url", extras::get_avatar_url(env.self)}}}
        });
    }

    else if (args[0] == "useful"){
        channel->send_embed({
            {"title", "Commands for useful"},
            {"description", "The Prefix is `dfb?`\n \n"
                            "**Offical DFB.eu Server » [Invite](https://discord.gg/42vDtZxZSt)**"},
            {"color", 0x7289D9},
            {"footer", {{"text", "Use dfb?help {category} to see more commands"}, {"icon_url", extras::get_avatar_url(msg->author)}}},
            {"thumbnail", {{"url", extras::get_avatar_url(env.self)}}}
        });
    }

    else {
        channel->send_embed({
             {"title", "I cannot find a category called `"+args[0]+"`"},
             {"description", "**__Available pages__** \n"
              "• `servermanagment`, `useful`"},
             {"color", 0xff0000}
        });
    }
}


//FULL HELP COMMANDS

void about(CMessage, CChannel channel, CDL::cmdargs&) {
    ostringstream aboutdata;
    timer::duration uptime = timer::now() - startup_time;
    auto uptime_hours = uptime.count() / 1000000000 / 60 / 60;

    aboutdata << "DFB - The offical Bot for Discordlist for Bots \n \n"
                 "**Memory Usage** \n"  << extras::get_mem::used() << " MB of " << extras::get_mem::total() << " MB \n \n"
                 "**Uptime** \n" << uptime_hours <<"h"
                 "\n";

    channel->send_embed({
        {"title", "Informations about DFB"},
        {"description", aboutdata.str()},
        {"color", 0x7289D9},
    });
}

void approve(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    if (args.size() < 2 ) {
        channel->send("Please mention the bot, and the botowner to execute the command!");
        return;
    }
    msg->remove();

    channel->send_embed({
        {"title", "Bot approved"},
        {"description", "The Bot "+args[0]+ " by "+args[1]+ " was approved by "+msg->author->get_mention()+"\n \n"
         "Your Bot is now available on the DFB website!"},
        {"color", 0x00ff00},


    });
}

void decline(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    if (args.size() < 4 ) {
        channel->send("Please mention the bot, the botowner, give the PACKAGE_NAME, and give an reason to decline a bot!!");
        return;
    }
    msg->remove();

    channel->send_embed({
        {"title", "Bot declined"},
        {"description", "The Bot "+args[0]+ " by "+args[1]+ " was declined by "+msg->author->get_mention()+"\n \n"
         "**Reason** \n"
         +args[2]+"\n \n"
         +args[3]},
        {"color", 0xff0000},


    });
}

void proc(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    if (args.size() < 2 ) {
        channel->send("Please mention the bot, and the botowner to execute the command!");
        return;
    }
    msg->remove();

    channel->send_embed({
        {"title", "Bot is in certification process"},
        {"description", "The Bot "+args[0]+ " by "+args[1]+ " is in cerfification process \n \n"
         "Please be patient! That takes time..."},
        {"color", 0xE4B400},


    });
}

void nproc(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    if (args.size() < 2 ) {
        channel->send("Please mention the bot, and the botowner to execute the command!");
        return;
    }
    msg->remove();

    channel->send_embed({
        {"title", "Bot won't be certified!"},
        {"description", "The Bot "+args[0]+ " by "+args[1]+ " won't be certified \n \n"
         "Sorry"+args[1]+ ", but we found a lot of mistakes. So the bot CANNOT be certified!"},
        {"color", 0x277ECD},


    });
}

void certified(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    if (args.size() < 2 ) {
        channel->send("Please mention the botowner, and the bot to execute the command!");
        return;
    }
    msg->remove();

    channel->send_embed({
        {"title", "Bot has been certified!"},
        {"description", "Hey "+args[0]+ "! We have something big to say you! Your bot, "+args[1]+ " was cerified by "
         +msg->author->get_mention()+"\n"
         "You are now a certified bot developer and your bot is one of the featured bots!"},
        {"color", 0x00FF00},


    });
}

// Warn

void warn(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    auto guild = channel->get_guild();
    if (not guild->has_perm(msg->author, Permissions::BAN_MEMBERS)){
        channel->send("You have no permissons to run this command!");
        return;
    }
    if (args.size() < 2) {
        channel->send("Please mention a user, and give a reason to warn");
        return;
    }
    auto target_userid = extras::find_user_id(guild, args[0]);
    fetch::user(target_userid, [guild, args, channel, msg] (CUser target_user) {
        if (not target_user){
            channel->send("Thats not an user!");
            return;
        }
        dbid id = to_dbid(target_user->id)+to_dbid(channel->guild_id);
        auto warns = env.db->get(id, "warns").as < int32_t >();
        warns++;
        nlohmann::json embed = {
                       {"title",  target_user->get_full_name()+" was warned"},
                       {"description", target_user->get_mention()+"was warned by "+msg->author->get_mention()+"\n"
                        "**Reason** \n"
                        +args[1]+"\n \n"
                        "User ID: " +to_string(target_user->id)+"\n "
                        +target_user->get_full_name()+" has now "+to_string(warns)+" warns \n"
                        "When this user have 3 warns, they will be banned"},
                        {"color", 0xD23B05},
                        {"thumbnail", {{"url", extras::get_avatar_url(target_user)}}}
        };
        channel->send_embed(embed);
        fetch::channel(768949790486036551, [embed] (CChannel channel) {
            channel->send_embed(embed);
        }, guild);
        if (warns == 3) {
            guild->ban(target_user, "User was warned 3 times.");
            warns = 0;
        }
        env.db->update(id, "warns", warns);
        env.db->update(id, "warn"+std::to_string(warns), args[1]);
    });

}

static const std::vector<std::string> get_table_tmpl(db_templates::type type) {
    using namespace db_templates;
    switch (type) {
        case user:
            return {"WARNS           INT                               ",
                    "WARN1           TEXT                              ",
                    "WARN2           TEXT                              ",
                    "WARN3           TEXT                              "};
       case _end: break;
    }
    return {};
}
static const std::map<std::string, std::string> get_record_tmpl(db_templates::type type) {
    using namespace db_templates;
    switch (type) {
        case user:
            return {
                       {"WARNS", "0"},
                       {"WARN1", ""},
                       {"WARN2", ""},
                       {"WARN3", ""}
                   };
       case _end: break;
    }
    return {};
}

// Warn

// Kick

void kick(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    auto guild = channel->get_guild();
    if (not guild->has_perm(msg->author, Permissions::KICK_MEMBERS)){
        channel->send("You have no permissons to run this command!");
        return;
    }
    if (args.size() < 2) {
        channel->send("Please mention a user, and give a reason to kick");
        return;
    }
    auto target_userid = extras::find_user_id(guild, args[0]);
    fetch::user(target_userid, [guild, args, channel, msg] (CUser target_user) {
        if (not target_user){
            channel->send("Thats not an user!");
            return;
        }
        nlohmann::json embed = {
                       {"title",  target_user->get_full_name()+" was kicked"},
                       {"description", target_user->get_mention()+"was kicked by "+msg->author->get_mention()+"\n"
                        "**Reason** \n"
                        +args[1]+"\n \n"
                        "User ID: " +to_string(target_user->id)+" \n"
                        +target_user->get_full_name()+" can join back with an invite"},
                        {"color", 0xFFA500},
                        {"thumbnail", {{"url", extras::get_avatar_url(target_user)}}}
        };
        channel->send_embed(embed);
        fetch::channel(768949790486036551, [embed] (CChannel channel) {
            channel->send_embed(embed);
        }, guild);
        guild->kick(target_user, args[1]);
    });

}

// Kick

// Ban

void ban(CMessage msg, CChannel channel, CDL::cmdargs& args) {
    auto guild = channel->get_guild();
    if (not guild->has_perm(msg->author, Permissions::BAN_MEMBERS)){
        channel->send("You have no permissons to run this command!");
        return;
    }
    if (args.size() < 2) {
        channel->send("Please mention a user, and give a reason to ban!");
        return;
    }
    auto target_userid = extras::find_user_id(guild, args[0]);
    fetch::user(target_userid, [guild, args, channel, msg] (CUser target_user) {
        if (not target_user){
            channel->send("Thats not an user!");
            return;
        }
        nlohmann::json embed = {
                       {"title",  target_user->get_full_name()+" was banned"},
                       {"description", target_user->get_mention()+"was banned by "+msg->author->get_mention()+"\n"
                        "**Reason** \n"
                        +args[1]+"\n \n"
                        "User ID: " +to_string(target_user->id)+" \n"
                        +target_user->get_full_name()+" cannot join back before being unbanned!"},
                        {"color", 0xFF0000},
                        {"thumbnail", {{"url", extras::get_avatar_url(target_user)}}}
        };
        channel->send_embed(embed);
        fetch::channel(768949790486036551, [embed] (CChannel channel) {
            channel->send_embed(embed);
        }, guild);
        guild->ban(target_user, args[1]);
    });

}

// Ban


int main(int argc, char **argv) {
    startup_time = timer::now();

    CDL::register_command("approve", approve, 2);
    CDL::register_command("echo", echo, 1);
    CDL::register_command("about", about, NO_ARGS);
    CDL::register_command("say", say, 1);
    CDL::register_command("invite", invite, NO_ARGS);
    CDL::register_command("help", help, NO_ARGS);
    CDL::register_command("about", about, NO_ARGS);
    CDL::register_command("decline", decline, 4);
    CDL::register_command("warn", warn, 2);
    CDL::register_command("embedsay", embedsay, 1);
    CDL::register_command("proc", proc, 2);
    CDL::register_command("nproc", nproc, 2);
    CDL::register_command("certified", certified, 2);
    CDL::register_command("kick", kick, 2);
    CDL::register_command("ban", ban, 2);

    cache::ctrl::message=false;


    CDL::handlers::get_prefix = [] (CChannel, function<void (const string&)> cb) {
        cb("dfb?");
    };

    CDL::handlers::in_main = [] () {
        // Initialise database client
        env.db = new Database(get_table_tmpl, get_record_tmpl);
    };
    CDL::intents::ready.push_back([] () {
        auto t = new PresenceScroller;

        t->presences.push_back([] () {
            Presence p;
            p.activities.push_back(Activity(
                "Discordlist for Bots",
                ActivityType::playing
            ));
            return p;
        });
       t->presences.push_back([] () {
            Presence p;
            p.activities.push_back(Activity(
                "bot registation form",
                ActivityType::watching
            ));
            return p;
        });
        t->speed = 12;
     });

    CDL::intents::guild_member_add.push_back([] (CMember member) {
        if (member->guild->id != 768930163647316048) return;
        fetch::channel(768933060737105961, [member] (CChannel channel) {
            channel->send_embed({
                {"title", "Welcome "+member->lazy_user->get_full_name()},
                {"description", "Hi "+member->lazy_user->get_mention()+"!!\n"
                 "Welcome to the official Discordlist for Bots server."},
                {"color", 0x7289D9},
                {"image", {{"url", "https://media.discordapp.net/attachments/768930163647316051/793810295608705024/Screenshot_20201230-125819.png?width=787&height=442"}}}
            });
        });
    });

    CDL::intents::guild_member_remove.push_back([] (const_CMember member) {
        if (member->guild->id != 768930163647316048) return;
        fetch::channel(768935397384257596, [member] (CChannel channel) {
            channel->send_embed({
                {"title", "Bye "+member->lazy_user->get_full_name()},
                {"description","Bye "+member->lazy_user->get_full_name()+ "\n"
                 "I hope, too see you later!"},
                {"color", 0xffffff}
            });
        });
    });

    using namespace CDL::intent_vals;
    CDL::main(argc, argv, GUILD_MESSAGES | DIRECT_MESSAGES | GUILD_MEMBERS);
}



