#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>
#include "iPinHw.hpp"
#include "iLcdHw.hpp"
#include "lcdHw.hpp"

LcdHw::LcdHw(iPinHw * enable, iPinHw * reg_select, iPinHw * read_write, iPinHw * db4, iPinHw * db5, iPinHw * db6, iPinHw * db7)
{
    this->enable = enable;
    this->reg_select = reg_select;
    this->read_write = read_write;
    this->db4 = db4;
    this->db5 = db5;
    this->db6 = db6;
    this->db7 = db7;

    enable->reset();
    reg_select->reset();
    read_write->reset();
    
    enable->output();
    reg_select->output();
    read_write->output();

    db7->input();
    db6->input();
    db5->input();
    db4->input();

    init();
}

LcdHw::~LcdHw()
{
    delete(reg_select);
    delete(read_write);
    delete(db4);
    delete(db5);
    delete(db6);
    delete(db7);
}

void LcdHw::write_data(uint8_t data)
{
    reg_select->set();
    read_write->reset();
    
    _delay_us(1);
    write(data);
    write(data<< 4 );
    _delay_us(40);
}

void LcdHw::clear_display()
{
    write_command(eLcdCommand::clear); //Display clear
    _delay_ms(2.1); //2.16mS
}

/* Local functions */

void LcdHw::init()
{
	//PoR
	//Wait > 15ms
	_delay_ms(16);
	
	//Function set
	write_command(eLcdCommand::functionSet);
	_delay_ms(5); //Wait > 4.1mS
	
	//Function set
	write_command(eLcdCommand::functionSet);
	_delay_us(200); //Wait > 100uS
	
	//Function set
	write_command(eLcdCommand::functionSet);
	_delay_us(200); //Wait > 100uS
	
	//Function set 4 bit operation
	write_command(eLcdCommand::functionSet4bit);
	_delay_us(80); //53uS
	
	//Function set number of display lines and char font
	write_command(eLcdCommand::functionSet4bit);
	_delay_us(80); //53uS
	
	//Display off
	write_command(eLcdCommand::displayOff);
	_delay_us(80); //53uS
	
	//Display clear
	write_command( eLcdCommand::clear );
	_delay_ms(4); //2.16mS
	
	//Entry mode set
	write_command(eLcdCommand::entryMode);
	_delay_us(80); //53uS
	
	//Display on
	write_command(eLcdCommand::displayOn);
	_delay_us(80); //53uS
}

void LcdHw::write(uint8_t data)
{
    PCICR &= ~( 1 << PCIE0 ); //Disable int
    
    //Set pins as outputs to write lcd data
    db7->output();
    db6->output();
    db5->output();
    db4->output();

    db7->reset();
    if(data & (1 << 7))
    {
        db7->set();
    }        
    db6->reset();
    if(data & (1 << 6))
    {
        db6->set();
    }        
    db5->reset();
    if(data & (1 << 5))
    {
        db5->set();
    }        
    db4->reset();
    if(data & (1 << 4))
    {
        db4->set();
    }        
    
    //Write thedataSetup time 40uS
    enable->set(); //Enable
    _delay_us(1); //implement 'Data set-up time' (80 nS) and 'Enable pulse width' (230 nS)
    enable->reset(); //Disable
    _delay_us(1); //implement 'Data hold time' (10 nS) and 'Enable cycle time' (500 nS)
    
    //Set pins as inputs to use for button
    db7->input();
    db6->input();
    db5->input();
    db4->input();
    
    PCICR |= ( 1 << PCIE0 ); //Re-enable int
}

void LcdHw::write_command(eLcdCommand command)
{
	reg_select->reset();
	read_write->reset();
	
	write(static_cast<uint8_t>(command));
	write(static_cast<uint8_t>(command) << 4 );
	_delay_us(40);
}
