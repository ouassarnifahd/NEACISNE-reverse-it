library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;


entity freq_tb is
--  Port ( );
end freq_tb;

architecture Behavioral of freq_tb is

component freq is
    Port ( clk : in STD_LOGIC;
           TTL : in STD_LOGIC;
           seg : out STD_LOGIC_VECTOR (6 downto 0);
           an : out STD_LOGIC_VECTOR (7 downto 0);
           dp : out STD_LOGIC);
end component;

signal clk : std_logic :='0';
signal TTL : std_logic :='0';

signal seg : std_logic_vector(6 downto 0);
signal an : std_logic_vector(7 downto 0);
signal dp : std_logic;

begin

dut: freq port map(
    clk => clk,
    TTL => TTL,
    seg => seg,
    an => an,
    dp => dp);

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
        wait for 350000 ns;
        TTL <= '1';
        wait for 350000 ns;
    end process;
    

end Behavioral;
