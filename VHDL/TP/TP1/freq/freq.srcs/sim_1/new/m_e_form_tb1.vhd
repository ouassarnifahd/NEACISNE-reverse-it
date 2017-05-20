library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity m_e_form_tb1 is
end m_e_form_tb1;

architecture Behavioral of m_e_form_tb1 is

    component m_e_form is
        Port ( clk : in STD_LOGIC;
               TTL : in STD_LOGIC;
               TTL_mef : out STD_LOGIC);
    end component m_e_form;

signal clk : std_logic :='0';
signal TTL : std_logic :='0';

signal TTL_mef : std_logic;

begin

    dut : m_e_form PORT MAP(
        clk => clk,
        TTL => TTL,
        TTL_mef => TTL_mef);

p1: process -- horloge 100 MHz : T=10ns
    begin
        clk <= '0';
        wait for 5 ns;
        clk <= '1';
        wait for 5 ns;
    end process;

p2: process
    begin
        TTL <= '0';
        wait for 55 ns;
        TTL <= '1';
        wait for 55 ns;
    end process;
    
end Behavioral;