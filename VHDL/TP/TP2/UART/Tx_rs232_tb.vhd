library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Tx_rs232_tb is
--  Port ( );
end Tx_rs232_tb;

architecture Behavioral of Tx_rs232_tb is

component Tx_rs232 is
    Port ( clk : in STD_LOGIC;
           write_d : in STD_LOGIC;
           data_o : in STD_LOGIC_VECTOR (7 downto 0);
           TX : out STD_LOGIC;
           busy : out STD_LOGIC;
           tox_tx : in STD_LOGIC);
end component;

signal clk : std_logic :='0';
signal write_d : std_logic :='0';
signal data_o : std_logic_vector (7 downto 0) :="00000001";

signal TX, busy, tox_tx : std_logic;

begin

u1: Tx_rs232 PORT MAP (clk=>clk, write_d=>write_d, data_o=> data_o, TX=> TX, busy => busy, tox_tx => tox_tx);

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

p3: process
begin
    tox_tx <='0';
    wait for 104 us;
    tox_tx <='1';
    wait for 10 ns;

end process;

end Behavioral;
