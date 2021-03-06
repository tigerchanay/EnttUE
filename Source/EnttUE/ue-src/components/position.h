#pragma once

#include "CoreMinimal.h"
#include "entt/entity/registry.hpp"
#include "core/component_authoring.h"
#include "position.generated.h"

USTRUCT(BlueprintType)
struct ENTTUE_API FPosition : public FVector {
	GENERATED_BODY()
	public:
	using FVector::FVector;
	FPosition(const FVector& other) : FVector(other) {}
};

USTRUCT(BlueprintType)
struct ENTTUE_API FPositionAuthoring : public FComponentAuthoring {
	GENERATED_BODY()

    public:
	void add_to_ecs(tc::ecs_registry &registry,
			tc::entity_handle handle) override
	{
		registry.emplace_or_replace<FPosition>(handle.id, value);
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FPosition value;
};
