#pragma once

#include "CoreMinimal.h"
#include "jobs/system_base.hpp"

namespace tc
{
class ENTTUE_API marshal_to_actor_system : public system_base<marshal_to_actor_system> {
	friend class system_base<marshal_to_actor_system>;

    private:
	void on_create();
	void on_schedule();
};

} // namespace tc