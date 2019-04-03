library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity uart is
    Port ( clk : in STD_LOGIC;
           write_d : in STD_LOGIC;
           data_o : in STD_LOGIC_VECTOR (7 downto 0);
           TX : out STD_LOGIC;
           busy : out STD_LOGIC);
end uart;

architecture Behavioral of uart is
    signal tox_tx_s : std_logic;

component Baudrate is
    Port ( clk : in STD_LOGIC;
           tox_tx : out STD_LOGIC);
end component;

component Tx_rs232 is
    Port ( clk : in STD_LOGIC;
           write_d : in STD_LOGIC;
           data_o : in STD_LOGIC_VECTOR (7 downto 0);
           TX : out STD_LOGIC;
           busy : out STD_LOGIC;
           tox_tx : in STD_LOGIC);
end component;

begin

u1: Baudrate port map(
    clk=>clk,
    tox_tx => tox_tx_s);
    
u2: Tx_rs232 port map(
    clk => clk,
    write_d => write_d,
    data_o => data_o,
    TX => TX,
    busy => busy,
    tox_tx => tox_tx_s);

end Behavioral;
