#include "common.h"
#include "ECS/ECS.h"
#include "render_system/render.h"

static const enum CompMask RENDER_COMPONENTS = COMP_RENDER|COMP_LOCATION;



int render_system(const struct WorldState *state)
{
    (void)state;

    Entity e;
    struct Render *render;
    struct Location *location;
    foreach_entity(e, RENDER_COMPONENTS) {
        render = get_render(e);
        location = get_location(e);
    }
}
