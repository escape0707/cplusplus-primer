#pragma once

#include <utility>

#include "QueryResult.h"
#include "TextQuery.h"

template <typename... Args>
TextQuery::QueryResult::QueryResult(key_type &&key,
                                    const shared_container_type &input,
                                    Args &&... args)
    : key_(std::move(key)),
      input_(input),
      line_numbers_(std::forward<Args>(args)...) {}
