/* Optional loader entry: Shop Framework owns the single native shortcut. */
#include "../../runtime/native/gameplay.h"
#include "../shop-framework/client.h"
int _fltused=0;
static int ms_started;
__declspec(dllexport) int MoonLab_ModStart(PTR domain,PTR game){
    if(ms_started)return 1;
    (void)integer;(void)boolean;(void)num;(void)prepare_hook;(void)install_hooks;
    if(!bind_runtime(domain,game))return 0;
    const MoonShop *shop=ms_connect(domain,game);if(!shop||!shop->open_modded)return 0;
    ms_started=1;return 1;
}
