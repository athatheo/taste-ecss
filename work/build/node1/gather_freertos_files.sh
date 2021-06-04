#!/bin/bash

if [ -z "${FREERTOS_PATH}" ]
then
    >&2 echo "Cannot find FreeRTOS distribution files."
    >&2 echo "Environment variable FREERTOS_PATH not set."
    exit 1
fi

FREERTOS_DISTRIBUTION="${FREERTOS_PATH}"

FREERTOS_FILES=(
    FreeRTOS/Source/timers.c
    FreeRTOS/Source/event_groups.c
    FreeRTOS/Source/include/list.h
    FreeRTOS/Source/include/portable.h
    FreeRTOS/Source/include/deprecated_definitions.h
    FreeRTOS/Source/include/task.h
    FreeRTOS/Source/include/message_buffer.h
    FreeRTOS/Source/include/queue.h
    FreeRTOS/Source/include/projdefs.h
    FreeRTOS/Source/include/croutine.h
    FreeRTOS/Source/include/StackMacros.h
    FreeRTOS/Source/include/mpu_prototypes.h
    FreeRTOS/Source/include/event_groups.h
    FreeRTOS/Source/include/mpu_wrappers.h
    FreeRTOS/Source/include/stack_macros.h
    FreeRTOS/Source/include/timers.h
    FreeRTOS/Source/include/semphr.h
    FreeRTOS/Source/include/FreeRTOS.h
    FreeRTOS/Source/tasks.c
    FreeRTOS/Source/list.c
    FreeRTOS/Source/queue.c
    FreeRTOS/Source/croutine.c
    FreeRTOS/Source/portable/GCC/MSP430FR5969/port.c
    FreeRTOS/Source/portable/GCC/MSP430FR5969/portmacro.h
)

for file in ${FREERTOS_FILES[*]}
do
    directory=$(dirname ${file})
    if [ ! -d "${directory}" ]
    then
        mkdir -p "${directory}"
    fi
    if [ ! -e "${file}" ]
    then
        cp "${FREERTOS_DISTRIBUTION}/${file}" "${file}"
    fi
done
