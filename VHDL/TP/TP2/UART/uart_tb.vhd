library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity uart_tb is
--  Port ( );
end uart_tb;

architecture Behavioral of uart_tb is

component uart is
    Port ( clk : in STD_LOGIC;
           write_d : in STD_LOGIC;
           data_o : in STD_LOGIC_VECTOR (7 downto 0);
           TX : out STD_LOGIC;
           busy : out STD_LOGIC);
end component;

signal clk : std_logic :='0';
signal write_d : std_logic :='0';
signal data_o : std_logic_vector (7 downto 0) :="00000001";

signal TX, busy : std_logic;

begin

u1: uart port map(clk=>clk, write_d=>write_d, data_o=>data_o, TX=>TX, busy=>busy);

p1:process

begin

    clk <='0';
    wait for 5 ns;
    clk <= '1';
    wait for 5 ns;
    
end process;

p2:process

begin

    write_d <='0';
    wait for 100 ns;
    write_d <='1';
    wait for 100 ns;

end process;


end Behavioral;
