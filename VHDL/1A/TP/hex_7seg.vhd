----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:34:52 03/02/2014 
-- Design Name: 
-- Module Name:    hex_7seg - Behavioral 
--
----------------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;


entity hex_7seg is
    Port ( hex : in  STD_LOGIC_VECTOR (3 downto 0);
           seg : out  STD_LOGIC_VECTOR (6 downto 0));
end hex_7seg;

architecture Behavioral of hex_7seg is

begin

	with hex select
	seg <=
--------------------------
--    seg           hex
--------------------------
	"1000000" when "0000" ,
	"1111001" when "0001" ,
	"0100100" when "0010" ,
	"0110000" when "0011" ,
	"0011001" when "0100" ,
	"0010010" when "0101" ,
	"0000010" when "0110" ,
	"1111000" when "0111" ,
	"0000000" when "1000" ,
	"0010000" when "1001" ,
	"0001000" when "1010" ,
	"0000011" when "1011" ,
	"1000110" when "1100" ,
	"0100001" when "1101" ,
	"0000110" when "1110" ,
	"0001110" when others;
	
end Behavioral;

