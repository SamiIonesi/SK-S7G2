/***********************************************************************************************************************
* File Name    : blinky_thread_entry.c
* Description  : This is a very simple example application that blinks all the LEDs on a board.
***********************************************************************************************************************/

#include "blinky_thread.h"
#include "bsp_api.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//Defines
#define LED1_PIN IOPORT_PORT_06_PIN_00
#define LED2_PIN IOPORT_PORT_06_PIN_01
#define LED3_PIN IOPORT_PORT_06_PIN_02

#define BUTTON1_PIN IOPORT_PORT_00_PIN_05
#define BUTTON2_PIN IOPORT_PORT_00_PIN_06

#define MAX_SEQUENCE_LENGTH 5
#define MAX_DIFFICULTY_LEVEL 7

const uint32_t difficulty_delays[MAX_DIFFICULTY_LEVEL] =
{
    500000,   // Nivel 1 (500.000 µs = 500 ms)
    400000,   // Nivel 2 (400.000 µs = 400 ms)
    300000,   // Nivel 3 (300.000 µs = 300 ms)
    200000,   // Nivel 4 (200.000 µs = 200 ms)
    100000,   // Nivel 5 (100.000 µs = 100 ms)
    75000,    // Nivel 6 (75.000 µs = 75 ms)
    50000,    // Nivel 7 (50.000 µs = 50 ms)
};

//Function declarations
void configure_LEDs_as_outputs();
void run_LEDs_in_line();
void simon_says();
void forward_backward();
void victory_light_show();
void game_over_light_show();
void configure_LEDs_and_Buttons();
void set_initial_LEDs_Off();
void initialize_random_number_generator();
void generate_random_sequence();
void special_victory_light_show();
void partial_special_victory_light_show();

void configure_LEDs_as_outputs()
{
    g_ioport_on_ioport.pinCfg(LED1_PIN, IOPORT_CFG_PORT_DIRECTION_OUTPUT);
    g_ioport_on_ioport.pinCfg(LED2_PIN, IOPORT_CFG_PORT_DIRECTION_OUTPUT);
    g_ioport_on_ioport.pinCfg(LED3_PIN, IOPORT_CFG_PORT_DIRECTION_OUTPUT);
}

void run_LEDs_in_line()
{
    configure_LEDs_as_outputs();
    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
    R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);

    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);

    R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);

    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);

    R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
}


void forward_backward()
{
    unsigned int go_ahead = 0;
    unsigned int go_back = 0;
    ioport_level_t last_button1_state = IOPORT_LEVEL_HIGH;
    ioport_level_t button1_state;
    ioport_level_t last_button2_state = IOPORT_LEVEL_HIGH;
    ioport_level_t button2_state;

    configure_LEDs_and_Buttons();
    set_initial_LEDs_Off();

    while (1)
    {
        g_ioport_on_ioport.pinRead(BUTTON1_PIN, &button1_state);
        g_ioport_on_ioport.pinRead(BUTTON2_PIN, &button2_state);

        if (button1_state == IOPORT_LEVEL_LOW && last_button1_state == IOPORT_LEVEL_HIGH)
        {
            R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);

            switch(go_ahead)
            {
                case 0:
                    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
                    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
                    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
                    go_ahead = 1;
                    go_back = 3;
                    break;

                case 1:
                    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
                    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
                    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
                    go_ahead = 2;
                    go_back = 0;
                    break;

                case 2:
                    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
                    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
                    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
                    go_ahead = 3;
                    go_back = 1;
                    break;

                case 3:
                    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
                    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
                    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
                    go_ahead = 0;
                    go_back = 2;
                    break;
            }

            R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);
        }

        if (button2_state == IOPORT_LEVEL_LOW && last_button2_state == IOPORT_LEVEL_HIGH)
        {
            R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);

            switch(go_back)
            {
                case 0:
                g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
                g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
                g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
                go_ahead = 1;
                go_back = 3;
                break;

            case 1:
                g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
                g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
                g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
                go_ahead = 2;
                go_back = 0;
                break;

            case 2:
                g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
                g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
                g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
                go_ahead = 3;
                go_back = 1;
                break;

            case 3:
                g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
                g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
                g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
                go_ahead = 0;
                go_back = 2;
                break;
            }

            R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);
        }

        last_button1_state = button1_state;
        last_button2_state = button2_state;
    }
}



void victory_light_show()
{
    for (int i = 0; i < 2; i++)
    {
        // Sequence 1: Turning on the LEDs one by one
        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);

        // Turn off the LEDs one by one
        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);

        // Sequence 2: All LEDs blink simultaneously
        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);
        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);

    }
}

void game_over_light_show(uint32_t delay)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(delay, BSP_DELAY_UNITS_MILLISECONDS);

        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(delay, BSP_DELAY_UNITS_MILLISECONDS);
    }
}

void partial_special_victory_light_show()
{
    for (int i = 0; i < 5; i++)
    {

        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
        g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
    }
}


void special_victory_light_show()
{
    partial_special_victory_light_show();
    game_over_light_show(100);
    partial_special_victory_light_show();
    set_initial_LEDs_Off();
}


void configure_LEDs_and_Buttons()
{
    configure_LEDs_as_outputs();
    g_ioport_on_ioport.pinCfg(BUTTON1_PIN, IOPORT_CFG_PORT_DIRECTION_INPUT);
    g_ioport_on_ioport.pinCfg(BUTTON2_PIN, IOPORT_CFG_PORT_DIRECTION_INPUT);
}

void set_initial_LEDs_Off()
{
    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);
    g_ioport_on_ioport.pinWrite(LED3_PIN, IOPORT_LEVEL_HIGH);

}

void initialize_random_number_generator()
{
    static unsigned int seed = 1234; //
    seed++;
    srand(seed);
}

void generate_random_sequence(int* sequence)
{

    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++)
    {
        sequence[i] = rand() % 2; // LED1 (0) or LED2 (1)
    }
}

void simon_says(void)
{
    int sequence[MAX_SEQUENCE_LENGTH];
    int sequence_length;
    int user_input_index;
    int difficulty_level;
    bool game_over;

    configure_LEDs_and_Buttons();
    set_initial_LEDs_Off();

    while (true)
    {
        // Reset game to level 1
        difficulty_level = 1;
        game_over = false;

        while (!game_over && difficulty_level <= MAX_DIFFICULTY_LEVEL)
        {
            sequence_length = 1;
            initialize_random_number_generator();
            generate_random_sequence(sequence);

            while (sequence_length <= MAX_SEQUENCE_LENGTH && !game_over)
            {
                // 1. second pause before displaying the sequence
                R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_SECONDS);

                // 2. Display sequence
                for (int i = 0; i < sequence_length; i++)
                {
                    if (sequence[i] == 0)
                    {
                        g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_LOW);
                    }
                    else
                    {
                        g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_LOW);
                    }

                    R_BSP_SoftwareDelay(difficulty_delays[difficulty_level - 1], BSP_DELAY_UNITS_MICROSECONDS);

                    g_ioport_on_ioport.pinWrite(LED1_PIN, IOPORT_LEVEL_HIGH);
                    g_ioport_on_ioport.pinWrite(LED2_PIN, IOPORT_LEVEL_HIGH);

                    R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
                }

                // 3. Check user response
                user_input_index = 0;
                while (user_input_index < sequence_length && !game_over)
                {
                    ioport_level_t button1_state, button2_state;
                    g_ioport_on_ioport.pinRead(BUTTON1_PIN, &button1_state);
                    g_ioport_on_ioport.pinRead(BUTTON2_PIN, &button2_state);

                    if (button1_state == IOPORT_LEVEL_LOW)
                    {
                        if (sequence[user_input_index] == 0)
                        {
                            user_input_index++;
                            R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
                        }
                        else
                        {
                            game_over = true;
                        }
                    }
                    else if (button2_state == IOPORT_LEVEL_LOW)
                    {
                        if (sequence[user_input_index] == 1)
                        {
                            user_input_index++;
                            R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);
                        }
                        else
                        {
                            game_over = true;
                        }
                    }
                }

                if (!game_over)
                {
                    sequence_length++;
                }
            }

            if (!game_over)
            {
                if(difficulty_level <= MAX_DIFFICULTY_LEVEL)
                {
                    victory_light_show();
                }

                difficulty_level++;
            }
        }

        if (difficulty_level > MAX_DIFFICULTY_LEVEL)
        {
            special_victory_light_show();
        }
        else
        {
            game_over_light_show(500);
        }
    }
}

/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the the threadx sleep function.
 * Only references two other modules including the BSP, IOPORT.
 *
 **********************************************************************************************************************/
void blinky_thread_entry(void)
{

    while (1)
    {

        //run_LEDs_in_line(); // game 1
        //forward_backward(); // game 2
        simon_says(); // game 3

    }
}
