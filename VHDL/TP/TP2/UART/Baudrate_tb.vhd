library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Baudrate is
end Baudrate;

architecture Behavioral of Baudrate_tb is

component Baudrate is
    Port ( clk : in STD_LOGIC;
           tox_tx : out STD_LOGIC);
end component;

signal clk:STD_LOGIC := '0';

 signal tox_tx : STD_LOGIC; 

begin

dut: Baudrate PORT MAP(clk => clk, tox_tx=>tox_tx);

p1: process -- horloge 100 MHz : T=10ns
    begin
        clk <= '0';
        wait for 5 ns;
        clk <= '1';
        wait for 5 ns;
    end process;

end Behavioral;
