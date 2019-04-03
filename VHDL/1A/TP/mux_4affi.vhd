----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:33:18 04/27/2014 
-- Design Name: 
-- Module Name:    mux_4affi - Behavioral 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity mux_4affi is
    Port ( data_i : in  STD_LOGIC_VECTOR (15 downto 0);
           sel : in  STD_LOGIC_VECTOR (1 downto 0);
           data_o : out  STD_LOGIC_VECTOR (3 downto 0);
           an : out  STD_LOGIC_VECTOR (7 downto 0)
          );
end mux_4affi;

architecture Behavioral of mux_4affi is

begin

	with sel select
	an(3 downto 0) <= 
	"1110" when "00",
	"1101" when "01",
	"1011" when "10",
	"0111" when others;

	with sel select
	data_o <= 
	data_i(3 downto 0)   when "00",
	data_i(7 downto 4)   when "01",
	data_i(11 downto 8)  when "10",
	data_i(15 downto 12) when others;
						
	an(7 downto 4) <= "1111";					

end Behavioral;

