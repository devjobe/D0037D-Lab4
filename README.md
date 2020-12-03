# D0037D Lab 4

```yaml
User: ojaebh-0  
Time estimate: 5h
Difficulty rating: easy
Visual Studio version: 2019
```

## Usage

The tasks are seperated into different executable projects.

## Reflection

> What did you learn? What did you know already?

There was not much new for me. I knew how to work with classes and how to solve issues that 
arise with unencapsulated memory allocations.

> What was difficult in the lab? How did you overcome it?

Trying to work with `cin::operator >>` and `std::getline / cin::get / cin::getline / ...`. I tried 
a few more different approaches to solving the problem but ended up just clearing any pending 
input from `cin` again which was not ideal. 

My previous conclusion was to not use `basic_istream::operator >>` on `cin` directly if you are 
reading line input as well. I thought maybe I had a different approach to make it work (easily) 
this time but ended up just wasting my time.

The end result of this became `Task1/Input.h`.

> How can the lab be improved?

In Task 6, the function signature for `checkMissing` is unusable. There is no way to for
the caller to know how many cards are in the array if all you return is a pointer.

Since the last ones are optional maybe allow the student to choose a game to implement.

> Additionally, write an estimate how many hours you spent on this lab.

About 1.5h for task 1.
About 1h for both 3 and 6.
About 30min for 2, 4 and 5.
Spent an hour refactoring Input.h but I don't count it as part of the lab.

