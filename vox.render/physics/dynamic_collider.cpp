//
//  dynamic_collider.cpp
//  vox.render
//
//  Created by 杨丰 on 2021/12/3.
//

#include "dynamic_collider.h"
#include "physics_manager.h"
#include "../entity.h"

namespace vox {
namespace physics {
DynamicCollider::DynamicCollider(Entity *entity) :
Collider(entity) {
    const auto &p = entity->transform->worldPosition();
    auto q = entity->transform->worldRotationQuaternion();
    q.normalize();
    
    _nativeActor = PhysicsManager::_nativePhysics()->createRigidDynamic(PxTransform(PxVec3(p.x, p.y, p.z),
                                                                                    PxQuat(q.v.x, q.v.y, q.v.z, q.r)));
}

float DynamicCollider::linearDamping() {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getLinearDamping();
}

void DynamicCollider::setLinearDamping(float newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setLinearDamping(newValue);
}

float DynamicCollider::angularDamping() {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getAngularDamping();
}

void DynamicCollider::setAngularDamping(float newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setAngularDamping(newValue);
}

Imath::V3f DynamicCollider::linearVelocity() {
    const auto &vel = static_cast<PxRigidDynamic *>(_nativeActor)->getLinearVelocity();
    return Imath::V3f(vel.x, vel.y, vel.z);
}

void DynamicCollider::setLinearVelocity(const Imath::V3f &newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setLinearVelocity(PxVec3(newValue.x, newValue.y, newValue.z));
}

Imath::V3f DynamicCollider::angularVelocity() {
    const auto &vel = static_cast<PxRigidDynamic *>(_nativeActor)->getAngularVelocity();
    return Imath::V3f(vel.x, vel.y, vel.z);
}

void DynamicCollider::setAngularVelocity(const Imath::V3f &newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setAngularVelocity(PxVec3(newValue.x, newValue.y, newValue.z));
}

float DynamicCollider::mass() {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getMass();
}

void DynamicCollider::setMass(float newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setMass(newValue);
}

Imath::Transform3 DynamicCollider::centerOfMass() {
    const auto &pose = static_cast<PxRigidDynamic *>(_nativeActor)->getCMassLocalPose();
    Imath::Transform3 trans;
    trans.setTranslation(Imath::V3f(pose.p.x, pose.p.y, pose.p.z));
    trans.setOrientation(Imath::Quatf(pose.q.w, pose.q.x, pose.q.y, pose.q.z));
    return trans;
}

void DynamicCollider::setCenterOfMass(const Imath::Transform3 &newValue) {
    const auto &p = newValue.translation();
    const auto &q = newValue.orientation();
    static_cast<PxRigidDynamic *>(_nativeActor)->setCMassLocalPose(PxTransform(PxVec3(p.x, p.y, p.z),
                                                                               PxQuat(q.v.x, q.v.y, q.v.z, q.r)));
}

Imath::V3f DynamicCollider::inertiaTensor() {
    const auto &tensor = static_cast<PxRigidDynamic *>(_nativeActor)->getMassSpaceInertiaTensor();
    return Imath::V3f(tensor.x, tensor.y, tensor.z);
}

void DynamicCollider::setInertiaTensor(const Imath::V3f &newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setMassSpaceInertiaTensor(PxVec3(newValue.x, newValue.y, newValue.z));
}

float DynamicCollider::maxAngularVelocity() {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getMaxAngularVelocity();
}

void DynamicCollider::setMaxAngularVelocity(float newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setMaxAngularVelocity(newValue);
}

float DynamicCollider::maxDepenetrationVelocity() {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getMaxDepenetrationVelocity();
}

void DynamicCollider::setMaxDepenetrationVelocity(float newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setMaxDepenetrationVelocity(newValue);
}

float DynamicCollider::sleepThreshold() {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getSleepThreshold();
}

void DynamicCollider::setSleepThreshold(float newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setSleepThreshold(newValue);
}

uint32_t DynamicCollider::solverIterations() {
    uint32_t posCounts;
    uint32_t velCounts;
    static_cast<PxRigidDynamic *>(_nativeActor)->getSolverIterationCounts(posCounts, velCounts);
    return posCounts;
}

void DynamicCollider::setSolverIterations(uint32_t newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setSolverIterationCounts(newValue);
}

//MARK: - PxRigidBodyFlag
PxRigidBodyFlags DynamicCollider::rigidBodyFlags() const {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getRigidBodyFlags();
}

void DynamicCollider::setRigidBodyFlag(PxRigidBodyFlag::Enum flag, bool value) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidBodyFlag(flag, value);
}

void DynamicCollider::setRigidBodyFlags(PxRigidBodyFlags inFlags) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidBodyFlags(inFlags);
}

bool DynamicCollider::isKinematic() {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getRigidBodyFlags().isSet(PxRigidBodyFlag::eKINEMATIC);
}

void DynamicCollider::setIsKinematic(bool newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidBodyFlag(PxRigidBodyFlag::eKINEMATIC, newValue);
}

//MARK: - RigidDynamicLockFlag
void DynamicCollider::setRigidDynamicLockFlag(PxRigidDynamicLockFlag::Enum flag, bool value) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidDynamicLockFlag(flag, value);
}

void DynamicCollider::setRigidDynamicLockFlags(PxRigidDynamicLockFlags flags) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidDynamicLockFlags(flags);
}

PxRigidDynamicLockFlags DynamicCollider::rigidDynamicLockFlags() const {
    return static_cast<PxRigidDynamic *>(_nativeActor)->getRigidDynamicLockFlags();
}

bool DynamicCollider::freezeRotation() {
    const auto x_lock = static_cast<PxRigidDynamic *>(_nativeActor)->getRigidDynamicLockFlags().isSet(PxRigidDynamicLockFlag::Enum::eLOCK_ANGULAR_X);
    const auto y_lock = static_cast<PxRigidDynamic *>(_nativeActor)->getRigidDynamicLockFlags().isSet(PxRigidDynamicLockFlag::Enum::eLOCK_ANGULAR_Y);
    const auto z_lock = static_cast<PxRigidDynamic *>(_nativeActor)->getRigidDynamicLockFlags().isSet(PxRigidDynamicLockFlag::Enum::eLOCK_ANGULAR_Z);
    return x_lock && y_lock && z_lock;
}

void DynamicCollider::setFreezeRotation(bool newValue) {
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidDynamicLockFlag(PxRigidDynamicLockFlag::Enum::eLOCK_ANGULAR_X, true);
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidDynamicLockFlag(PxRigidDynamicLockFlag::Enum::eLOCK_ANGULAR_Y, true);
    static_cast<PxRigidDynamic *>(_nativeActor)->setRigidDynamicLockFlag(PxRigidDynamicLockFlag::Enum::eLOCK_ANGULAR_Z, true);
}

void DynamicCollider::applyForce(const Imath::V3f &force) {
    static_cast<PxRigidDynamic *>(_nativeActor)->addForce(PxVec3(force.x, force.y, force.z));
}

void DynamicCollider::applyTorque(const Imath::V3f &torque) {
    static_cast<PxRigidDynamic *>(_nativeActor)->addTorque(PxVec3(torque.x, torque.y, torque.z));
}

void DynamicCollider::setKinematicTarget(const Imath::Transform3 &pose) {
    const auto &p = pose.translation();
    const auto &q = pose.orientation();
    static_cast<PxRigidDynamic *>(_nativeActor)->setKinematicTarget(PxTransform(PxVec3(p.x, p.y, p.z), PxQuat(q.v.x, q.v.y, q.v.z, q.r)));
}

void DynamicCollider::putToSleep() {
    static_cast<PxRigidDynamic *>(_nativeActor)->putToSleep();
}

void DynamicCollider::wakeUp() {
    static_cast<PxRigidDynamic *>(_nativeActor)->wakeUp();
}

void DynamicCollider::_onLateUpdate() {
    const auto &transform = entity()->transform;
    
    PxTransform pose = _nativeActor->getGlobalPose();
    transform->setWorldPosition(Imath::V3f(pose.p.x, pose.p.y, pose.p.z));
    transform->setWorldRotationQuaternion(Imath::Quatf(pose.q.w, pose.q.x, pose.q.y, pose.q.z));
    _updateFlag->flag = false;
}

}
}
