library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: UART --

entity UART is
    Port ( clk : in STD_LOGIC;
           write_d : in STD_LOGIC;
           data_o : in STD_LOGIC_VECTOR;
           top_tx : in STD_LOGIC;
           tx : out STD_LOGIC;
           busy : out STD_LOGIC);
end UART;

architecture Behavioral of UART is
    signal top_tx_s : STD_LOGIC;

component Baudrate is
    Port ( clk : in STD_LOGIC;
           top_tx : out STD_LOGIC);
end component Baudrate;

component tx_rs232 is
    Port ( clk : in STD_LOGIC;
           write_d : in STD_LOGIC;
           data_o : in STD_LOGIC_VECTOR;
           top_tx : in STD_LOGIC;
           tx : out STD_LOGIC;
           busy : out STD_LOGIC);
end component tx_rs232;

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
