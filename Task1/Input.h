/*
Utility functions handling line input.
*/

#pragma once

#include <iostream>
#include <string>
#include <optional>
#include <algorithm>
#include <string_view>

namespace util {

inline void cin_discard_pending() {
  std::cin.sync();
  std::cin.clear();
  std::cin.seekg(0, std::ios_base::end);
  std::cin.clear();
}

// Trim " \t\r\n" from start
inline std::string_view trim_start(std::string_view s) {
  auto const pos = s.find_first_not_of(" \t\r\n");
  if (pos == s.npos) {
    return {};
  }
  s.remove_prefix(pos);
  return s;
}

// Trim " \t\r\n" from end
inline std::string_view trim_end(std::string_view s) {
  auto const pos = s.find_last_not_of(" \t\r\n");
  if (pos == s.npos) {
    return {};
  }
  return s.substr(0, pos + 1);
}
// Trim " \t\r\n" from start and end
inline std::string_view trim(std::string_view s) {
  return trim_start(trim_end(s));
}

// Case insensitive compare
inline bool like(std::string_view lhs, std::string_view rhs) {
  return lhs.size() == rhs.size() &&
         std::equal(
             lhs.begin(), lhs.end(), rhs.begin(),
             [](unsigned char a, unsigned char b) { return std::toupper(a) == std::toupper(b); });
}

// Print out prompt to stdout and reads line from stdin.
inline std::string input_raw(const char *prompt = "") {
  std::cout << prompt;
  std::string result;
  std::getline(std::cin, result);
  return result;
}

// Retrieves a line from stdin using input_raw and returns the trimmed output.
inline std::string input_line(const char *prompt = "") {
  auto s = input_raw(prompt);
  // Fixme
  s = trim(s);
  return s;
}

// Uses input_raw to parse an i32.
inline std::optional<int> input_i32(const char *prompt = "") {
  auto const input = input_raw(prompt);
  auto const trimmed = trim(input);
  if (trimmed.size()) {
    char *end;
    int result = std::strtol(trimmed.data(), &end, 10);    
    if (end != trimmed.data() && trimmed.data() + trimmed.size() == end) {
      return result;
    }
  }
  return {};
}

// Uses input_raw to parse an f32.
inline std::optional<float> input_f32(const char* prompt = "") {
  auto const input = input_raw(prompt);
  auto const trimmed = trim(input);
  if (trimmed.size()) {
    char *end;
    const float result = std::strtof(trimmed.data(), &end);
    if (end != trimmed.data() && trimmed.data() + trimmed.size() == end) {
      return result;
    }
  }
  return {};
}



// Uses input_raw to parse case insensitivly true/false t/f 1/0 yes/no y/n
inline std::optional<bool> input_bool(const char *prompt = "") {
  auto const input = input_raw(prompt);
  auto const trimmed = trim(input);
  if (trimmed.size()) {
    if (like("true", trimmed) || like("yes", trimmed) || like("y", trimmed) || like("t", trimmed) || trimmed == "1")
      return true;
    if (like("false", trimmed) || like("no", trimmed) || like("n", trimmed) || like("f", trimmed) || trimmed == "0")
      return false;
  }
  return {};
}


// Returns:
// true: If given input from input_raw is true/yes/y/t/1 (case insensitivly).
// def: If no input was given.
// false: For any other input.
inline bool input_yesno(const char *prompt = "", bool def = false) {
  auto const input = input_raw(prompt);
  auto const trimmed = trim(input);
  if (trimmed.size()) {
    if (like("true", trimmed) || like("yes", trimmed) || like("y", trimmed) ||
        like("t", trimmed) || trimmed == "1") {
      return true;
    }
    return false;
  }
  return def;
}



// Handles multiple values on a single line seperated by space, tab or comma
class repeated_input {

public:
  repeated_input(const char *prompt = "")
      : input(input_raw(prompt)), view(trim(this->input)) {}

  std::optional<float> f32() {
    trim_comma();
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

  bool has_input() const { return view.size() != 0; }

private:
  const std::string input;
  std::string_view view;

  void trim_comma() {
    view.remove_prefix(std::min(view.find_first_not_of(", \t"), view.size()));
  }
};

// Returns the optional value only if it's in the optional inclusive range.
inline std::optional<int>
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
inline std::optional<float>
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