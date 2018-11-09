/**
 * @file ECS.h
 * @brief An Entity-Conponent system
 *
 * The ECS is implemented with the following Heirarchy:
 * - struct World
 *   - The global state of the engine world
 * - Entity
 *   - An id that associates an entity with its components
 * - Component structs
 *   - A struct that an entity is able to store data to
 * - System
 *   - A function that maps over components, making modifications
 * - SubSystem
 *   - A System called from within another System
 */
#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "common.h"
#include "ECS/components.h"

#define MAX_ENTITIES 100

typedef int32_t Entity;

/****************************************************************************/

#define AS_ENUMERATION(_type, _name, ename, ct) \
    COMP_ ## ename = (1 << ct),
/**
 * @brief The bitmask that determines what components an entity has
 *
 * The X macro expands each component as an enumeration value
 * which can be used as a bitmask
 */
enum CompMask {
    COMP_NONE = 0,
    COMPONENTS(AS_ENUMERATION)
};

/**
 * @brief A bitmask that can be used to emulate an 'empty' component
 */
enum TagMask {
    TAG_NONE = 0,
};

/****************************************************************************/

#define AS_STORAGE(typename, realname, _ename, _ct) \
    typename realname[MAX_ENTITIES];
/** 
 * @brief The global World structure
 *
 * This contains all components. For now there are a static number
 * of entities.
 * The X macro expands as an array for each component
 */
ATTR_INTERNAL 
struct World {
    uint32_t entity_count;
    enum CompMask mask[MAX_ENTITIES];
    COMPONENTS(AS_STORAGE)
} g_world;

/****************************************************************************/

static inline void set_components(Entity e, enum CompMask components) {
    g_world.mask[e] = components;
}
static inline enum CompMask get_components(Entity e) {
    return g_world.mask[e];
}
static inline void add_components(Entity e, enum CompMask components) {
    g_world.mask[e] |= components;
}

/**
 * @brief The component getters
 */
#define AS_GETTERS(typename, realname, _a, _b) \
    static inline typename *get_ ## realname(Entity e) { \
        ASSERT(e < MAX_ENTITIES); \
        return &g_world.realname[e]; \
    }
COMPONENTS(AS_GETTERS)

/****************************************************************************/

static inline Entity gen_entity(enum CompMask components) {
    Entity e = g_world.entity_count++;
    set_components(e, components);
    return e;
}
static inline void del_entity(Entity e) {
    // Do nothing for now
    (void)e;
}

/****************************************************************************/

/**
 * @brief Iterate over all entities with given components
 */
#define foreach_entity(e, mask) \
    for ((e) = 0; (e) < g_world.entity_count && (e) < MAX_ENTITIES; (e)++) \
        if (((e) & (mask)) == (mask))
 
#undef AS_ENUMERATION
#undef AS_STORAGE
#undef AS_GETTERS

#endif
