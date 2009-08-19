################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/tile_connections.cpp 

CC_SRCS += \
../src/bag.cc \
../src/bottom_side.cc \
../src/bottom_side_connections.cc \
../src/carcassonne.cc \
../src/game.cc \
../src/left_side.cc \
../src/left_side_connections.cc \
../src/position.cc \
../src/right_side.cc \
../src/right_side_connections.cc \
../src/side.cc \
../src/side_connections.cc \
../src/string_utility.cc \
../src/surface.cc \
../src/tile.cc \
../src/tile_impl.cc \
../src/tile_set.cc \
../src/top_side.cc \
../src/top_side_connections.cc \
../src/valid_tiles.cc 

OBJS += \
./src/bag.o \
./src/bottom_side.o \
./src/bottom_side_connections.o \
./src/carcassonne.o \
./src/game.o \
./src/left_side.o \
./src/left_side_connections.o \
./src/position.o \
./src/right_side.o \
./src/right_side_connections.o \
./src/side.o \
./src/side_connections.o \
./src/string_utility.o \
./src/surface.o \
./src/tile.o \
./src/tile_connections.o \
./src/tile_impl.o \
./src/tile_set.o \
./src/top_side.o \
./src/top_side_connections.o \
./src/valid_tiles.o 

CC_DEPS += \
./src/bag.d \
./src/bottom_side.d \
./src/bottom_side_connections.d \
./src/carcassonne.d \
./src/game.d \
./src/left_side.d \
./src/left_side_connections.d \
./src/position.d \
./src/right_side.d \
./src/right_side_connections.d \
./src/side.d \
./src/side_connections.d \
./src/string_utility.d \
./src/surface.d \
./src/tile.d \
./src/tile_impl.d \
./src/tile_set.d \
./src/top_side.d \
./src/top_side_connections.d \
./src/valid_tiles.d 

CPP_DEPS += \
./src/tile_connections.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


