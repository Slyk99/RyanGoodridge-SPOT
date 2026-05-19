import os
import sys
import time

# Set environment variables to suppress GPIO warnings
os.environ['JETSON_GPIO_FORCE_WARNINGS'] = '0'
os.environ['JETSON_GPIO_WARN_NOT_DEVKIT'] = '0'

try:
    import Jetson.GPIO as GPIO
    GPIO.setwarnings(False)
except ImportError:
    print("Warning: Jetson.GPIO not available. Functions will not work on non-Jetson systems.")
    GPIO = None


def set_gpio_pin(pin, value):
    """
    Set a GPIO pin to HIGH (1) or LOW (0).
    
    Args:
        pin (int): GPIO pin number
        value (int): 1 for HIGH/ON, 0 for LOW/OFF
    
    Returns:
        bool: True if successful, False otherwise
    """
    if GPIO is None:
        print("Error: Jetson.GPIO not available")
        return False
    
    if value not in [0, 1]:
        print("Error: Value must be 0 or 1")
        return False
    
    try:
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(pin, GPIO.OUT)
        GPIO.output(pin, value)
        time.sleep(0.1)  # Small delay to ensure pin is set
        print(f'GPIO pin {pin} set to {value}')
        return True
    except Exception as e:
        print(f"Error setting GPIO pin {pin}: {e}")
        return False
    finally:
        try:
            GPIO.cleanup()
        except:
            pass


def pucks_on():
    """Turn pucks ON (Pin 11)."""
    print("Turning pucks ON")
    return set_gpio_pin(11, 1)


def pucks_off():
    """Turn pucks OFF (Pin 11)."""
    print("Turning pucks OFF")
    return set_gpio_pin(11, 0)


def all_pins_off():
    """Turn off all GPIO pins (pucks + thrusters)."""
    pins = [11, 7, 12, 13, 15, 16, 18, 22, 23]
    success_count = 0
    
    print("Turning off all GPIO pins...")
    
    for pin in pins:
        if set_gpio_pin(pin, 0):
            success_count += 1
            print(f"  Pin {pin}: OFF")
        else:
            print(f"  Pin {pin}: FAILED")
    
    print(f"Successfully turned off {success_count}/{len(pins)} pins")
    return success_count == len(pins)


def cycle_thrusters():
    """
    Cycle through all thruster pins for 0.5 seconds each.
    
    Returns:
        tuple: (success, failed_pins)
    """
    thruster_pins = [7, 12, 13, 15, 16, 18, 22, 23]
    duration = 0.5  # 0.5 seconds per pin
    failed_pins = []
    
    print(f"Starting thruster check - {len(thruster_pins)} pins, {duration}s each")
    print(f"Total duration: {len(thruster_pins) * duration} seconds")
    
    for i, pin in enumerate(thruster_pins, 1):
        print(f"Activating thruster {i}/8 (Pin {pin})...")
        
        # Turn pin ON
        if not set_gpio_pin(pin, 1):
            print(f"  Failed to turn ON pin {pin}")
            failed_pins.append(pin)
            continue
        
        # Wait
        time.sleep(duration)
        
        # Turn pin OFF
        if not set_gpio_pin(pin, 0):
            print(f"  Failed to turn OFF pin {pin}")
            failed_pins.append(pin)
        else:
            print(f"  Pin {pin}: Complete")
    
    success = len(failed_pins) == 0
    if success:
        print("Thruster check completed successfully!")
    else:
        print(f"Thruster check completed with {len(failed_pins)} failed pins: {failed_pins}")
    
    return success, failed_pins


# Example usage
if __name__ == "__main__":
    print("GPIO Control Functions - Local Mode")
    print("Available functions:")
    print("  pucks_on() - Turn pucks on")
    print("  pucks_off() - Turn pucks off") 
    print("  cycle_thrusters() - Test all thrusters")
    print("  all_pins_off() - Turn off all pins")