library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity controle_tb is
--  Port ( );
end controle_tb;

architecture Behavioral of controle_tb is

    component controle is
        Port ( clk : in STD_LOGIC;
                   valid : out STD_LOGIC;
                   raz : out STD_LOGIC;
                   verr : out STD_LOGIC);
    end component controle;

signal clk : std_logic :='0';

signal valid : std_logic;
signal raz : std_logic;
signal verr : std_logic;

begin

    dut : controle PORT MAP(
            clk => clk,
            valid => valid,
            raz => raz,
            verr => verr);
            
p1: process -- horloge 100 MHz : T=10ns
                begin
                    clk <= '0';
                    wait for 5 ns;
                    clk <= '1';
                    wait for 5 ns;
                end process;
             
end Behavioral;
