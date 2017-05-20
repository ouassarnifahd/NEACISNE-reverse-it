library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity compteur0_tb is
--  Port ( );
end compteur0_tb;

architecture Behavioral of compteur0_tb is

    component compteur0 is
        Port ( clk : in STD_LOGIC;
            TTL_mef : in STD_LOGIC;
            valid : in STD_LOGIC;
            raz : in STD_LOGIC;
            freq : out STD_LOGIC_VECTOR (15 downto 0));
    end component compteur0;

signal clk : std_logic :='0';
signal TTL_mef : STD_LOGIC :='0';
signal valid : std_logic :='0';
signal raz : std_logic :='0';

signal freq : std_logic_vector (15 downto 0);

begin

    dut : compteur0 PORT MAP(
            clk => clk,
            TTL_mef => TTL_mef,
            valid => valid,
            raz => raz,
            freq => freq);

p1: process
                begin
                    clk <= '0';
                    wait for 5 ns;
                    clk <= '1';
                    wait for 5 ns;
                end process;

p2: process
    begin
        TTL_mef <= '0';
        wait for 100 ns;
        TTL_mef <= '1';
        wait for 10 ns;
    end process;
    
p3:process
    begin
        raz <='0';
        wait for 100000000 ns;
        raz <= '1';
        wait;
    end process;

p4:process
    begin
        valid <='1';
        wait for 100000000 ns;
        valid <='0';
        wait;
    end process;

end Behavioral;
