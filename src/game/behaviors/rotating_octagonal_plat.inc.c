// rotating_octagonal_plat.inc.c
#include "levels/pss/header.h"

static const Collision *sOctagonalPlatformCollision[] = {
    0,
    rr_seg7_collision_07029508,
    bits_octagonal_collision_0701AA84,
};

static s16 sOctagonalPlatformAngularVelocities[] = { 300, -300, 600, -600 };

void bhv_rotating_octagonal_plat_init(void) {
    o->collisionData = segmented_to_virtual(sOctagonalPlatformCollision[GET_BPARAM2(o->oBehParams)]);
    o->oAngleVelYaw = sOctagonalPlatformAngularVelocities[GET_BPARAM1(o->oBehParams)];
}

void bhv_rotating_octagonal_plat_loop(void) {
    o->oFaceAngleYaw += o->oAngleVelYaw;
}
