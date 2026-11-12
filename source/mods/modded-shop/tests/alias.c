/* The optional alias starts no input handler and never opens a shop on load. */
#include <assert.h>
#include "../../shop-framework/sdk.h"
typedef void *PTR;
static int binds,connects,binding=1,available=1,opens;
static int open_shop(void *walker){(void)walker;opens++;return 1;}
static MoonShop api={.abi=MS_ABI,.size=sizeof(MoonShop),.open_modded=open_shop};
static int bind_runtime(PTR d,PTR g){(void)d;(void)g;binds++;return binding;}
static const MoonShop *ms_connect(PTR d,PTR g){(void)d;(void)g;connects++;return available?&api:0;}
static int integer,boolean,num,prepare_hook,install_hooks;
#include "shop-alias-runtime.h"
int main(void){
    binding=0;assert(!MoonLab_ModStart(0,0)&&!ms_started&&binds==1&&!connects);
    binding=1;available=0;assert(!MoonLab_ModStart(0,0)&&!ms_started&&connects==1);
    available=1;api.open_modded=0;assert(!MoonLab_ModStart(0,0)&&!ms_started);
    api.open_modded=open_shop;assert(MoonLab_ModStart(0,0)&&ms_started&&!opens);
    int previous_binds=binds,previous_connects=connects;
    assert(MoonLab_ModStart(0,0)&&binds==previous_binds&&connects==previous_connects&&!opens);
    return 0;
}
