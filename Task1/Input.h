/*
Utility functions handling line input.
*/

#pragma once

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

namespace util {

// Trim " \t\r\n" from start
constexpr std::string_view trim_start(std::string_view s) {
  auto const pos = s.find_first_not_of(" \t\r\n");
  if (pos == s.npos) {
    return {};
  }
  s.remove_prefix(pos);
  return s;
}

// Trim " \t\r\n" from end
constexpr std::string_view trim_end(std::string_view s) {
  auto const pos = s.find_last_not_of(" \t\r\n");
  if (pos == s.npos) {
    return {};
  }
  return s.substr(0, pos + 1);
}
// Trim " \t\r\n" from start and end
constexpr std::string_view trim(std::string_view s) {
  return trim_start(trim_end(s));
}

// Case insensitive compare
constexpr bool like(std::string_view lhs, std::string_view rhs) {
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin(),
                    [](unsigned char a, unsigned char b) {
                      return std::toupper(a) == std::toupper(b);
                    });
}

// Tries to remove case insenitive word by matching pattern followed by end of
// string or std::isspace
constexpr bool remove_prefix_ciw(std::string_view &view,
                                 std::string_view pattern) {
  if (like(view.substr(0, pattern.size()), pattern) &&
      (view.size() == pattern.size() ||
       std::isspace(*(view.data() + pattern.size())))) {
    view.remove_prefix(pattern.size());
    return true;
  } else {
    return false;
  }
}

template <typename T> std::optional<T> parse_input(std::string_view &view);

template <>
constexpr std::optional<int> parse_input<int>(std::string_view &view) {
  if (view.size()) {
    char *end;
    const int result = std::strtol(view.data(), &end, 10);
    if (end != view.data()) {
      view.remove_prefix(end - view.data());
      return result;
    }
  }
  return {};
}

template <>
constexpr std::optional<float> parse_input<float>(std::string_view &view) {
  if (view.size()) {
    char *end;
    const float result = std::strtof(view.data(), &end);
    if (end != view.data()) {
      view.remove_prefix(end - view.data());
      return result;
    }
  }
  return {};
}

// Parse case insensitivly true/false 1/0 yes/no y/n
template <>
constexpr std::optional<bool> parse_input<bool>(std::string_view &view) {
  if (view.size()) {
    if (remove_prefix_ciw(view, "true") || remove_prefix_ciw(view, "yes") ||
        remove_prefix_ciw(view, "y") || remove_prefix_ciw(view, "1")) {
      return true;
    }
    if (remove_prefix_ciw(view, "false") || remove_prefix_ciw(view, "no") ||
        remove_prefix_ciw(view, "n") || remove_prefix_ciw(view, "0")) {
      return false;
    }
  }
  return {};
}

class Input {
public:
  Input &prompt(std::string_view prompt) {
    std::cout << prompt;
    std::getline(std::cin, this->input);
    this->view = trim(this->input);
    return *this;
  }

  // Returns the remaining input on the line.
  std::string line() const { return std::string(this->view); }


  // Parses a value and checks that there is no remaining input
  template <typename T> constexpr std::optional<T> only() {
    auto res = parse_input<T>(this->view);
    if (view.size()) {
      return {};
    }
    return res;
  }

  // Skips ", \t" and parses a value
  template <typename T> constexpr std::optional<T> elem() {
    view.remove_prefix(std::min(view.find_first_not_of(", \t"), view.size()));
    return parse_input<T>(this->view);
  }

  // Tries to case insenitive match pattern followed by end of input or
  // std::isspace.
  constexpr bool match_like(std::string_view pattern) {
    return remove_prefix_ciw(this->view, pattern);
  }

  // Returns true if input matches true, yes, y, or 1. If no input is
  // remaining/given then def is returned.
  constexpr bool yesno(bool def = false) {
    return view.size() ? (match_like("true") || match_like("yes") ||
                          match_like("y") || match_like("1"))
                       : def;
  }

  /* Unused
  // Parses a value
  template <typename T> constexpr std::optional<T> maybe() {
    return parse_input<T>(this->view);
  }

  constexpr bool empty() const { return view.size() == 0; }
  */

private:
  std::string input;
  std::string_view view;
};

// Returns the optional value only if it's in the optional inclusive range.
constexpr std::optional<int>
in_range(std::pair<std::optional<int>, std::optional<int>> range,
         std::optional<int> value) {
  if (value) {
    auto const v = *value;
    auto const [min, max] = range;
    if ((min && v < *min) || (max && v > *max)) {
      return {};
    }
  }

  return value;
}

// Returns the optional value only if it's in the optional inclusive range.
constexpr std::optional<float>
in_range(std::pair<std::optional<float>, std::optional<float>> range,
         std::optional<float> value) {
  if (value) {
    auto const v = *value;
    auto const [min, max] = range;
    if ((min && v < *min) || (max && v > *max)) {
      return {};
    }
  }
  return value;
}

} // namespace util