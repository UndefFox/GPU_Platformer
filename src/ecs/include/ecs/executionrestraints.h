#pragma once

enum class ExecutionRestraintType  {
    None,
    Dependencies
};


template <enum ExecutionRestraintType>
struct ExecutionRestraint;
