#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "core/entity_handle.hpp"
#include "ecs_world_actor.h"
#include "convert_to_ecs.generated.h"

UCLASS(ClassGroup = (ECS), meta = (BlueprintSpawnableComponent), Config = Game)
class ENTTUE_API UConvertToEcsComponent : public UActorComponent {
	GENERATED_BODY()

    public:
	UConvertToEcsComponent();
	void BeginPlay() override;

    private:
	tc::entity_handle register_world();
	void register_components();

	tc::entity_handle handle;
	AEcsWorldActor *world_actor;

	UPROPERTY(Config)
	TSubclassOf<AEcsWorldActor> world_type;
};
